"""Run the isolated EE-GCC 3.2-ee-040921 C compiler without output edits.

Windows uses headless WSL with a private, hash-checked 32-bit runtime.
See docs/TOOLCHAIN.md for profile inputs and proof boundaries.
"""
from __future__ import annotations

import hashlib
import os
from pathlib import Path
import shlex
import subprocess
import sys

from ee29_01 import wsl_path

ROOT = Path(__file__).resolve().parent.parent
VERSION = '3.2-ee-040921'
FILES = {
    'bin/ee-gcc': 'a5095b5d7b55f91535b12e48e9d808170fa9fb8c0620c43c2fb61379b1a3663a',
    f'lib/gcc-lib/ee/{VERSION}/cc1': '0bcc90bd23e10698e75047db9a84ea47e753791115fdd23d6f637a544f6d257d',
    'runtime/ld-2.3.6.so': 'd5a16aee4a04db7fa27a5c071a0bef62002ee679bf5ecce51e383003cf840fd8',
    'runtime/libc.so.6': '7b091aee7173e3a7cbddc6630fa6b0d0106944b5618b0b27c2c058ea9c3d92eb',
}


def compile_source(source: Path, output: Path, flags: list[str], *,
                   version: str = VERSION, files: dict[str, str] | None = None,
                   profile: Path | None = None, distro: str | None = None,
                   label: str | None = None) -> int:
    profile = (profile or Path(os.environ.get('EE32_040921_ROOT', ROOT / 'build/isolated/ee-gcc3.2-040921'))).resolve()
    files = FILES if files is None else files
    tag = version.removeprefix('3.2-ee-')
    label = label or 'ee32-' + tag
    for relative, expected in files.items():
        path = profile / relative
        if not path.is_file() or hashlib.sha256(path.read_bytes()).hexdigest() != expected:
            raise ValueError(f'@{label} missing or unverified profile file: {path} (docs/TOOLCHAIN.md)')

    distro = distro or os.environ.get('EE32_040921_WSL_DISTRO', 'docker-desktop')
    convert = (lambda path: wsl_path(str(path.resolve()), distro)) if os.name == 'nt' else (lambda path: str(path.resolve()))
    wrappers = output.parent / (output.stem + '_' + label.replace('-', '_'))
    wrappers.mkdir(parents=True, exist_ok=True)
    loader = convert(profile / 'runtime/ld-2.3.6.so')
    runtime = convert(profile / 'runtime')
    cc1 = convert(profile / f'lib/gcc-lib/ee/{version}/cc1')
    command = [loader, '--library-path', runtime, cc1]
    wrapper = wrappers / 'cc1'
    wrapper.write_text('#!/bin/sh\nexec ' + shlex.join(command) + ' "$@"\n', newline='\n')
    driver = convert(profile / 'bin/ee-gcc')
    compiler = [loader, '--library-path', runtime, driver]
    script = 'cd ' + shlex.quote(convert(ROOT)) + ' && chmod +x ' + shlex.join([driver, loader, cc1, convert(wrapper)])
    # Keep old 32-bit filesystem interfaces on native Linux storage. Copy
    # byte-identical inputs and emitted assembly; never rewrite instructions.
    script += ' && work=$(mktemp -d /tmp/rac4-' + label + '.XXXXXXXX)'
    # This driver's executable search also uses 32-bit stat(), so its
    # cc1 wrapper must live on native storage along with the inputs.
    script += ' && mkdir "$work/bin" && cp ' + shlex.quote(convert(wrapper)) + ' "$work/bin/cc1"'
    script += ' && chmod +x "$work/bin/cc1"'
    cpp = f'lib/gcc-lib/ee/{version}/cpp0'
    if cpp in files:
        cpp_command = [loader, '--library-path', runtime, convert(profile / cpp)]
        cpp_wrapper = wrappers / 'cpp0'
        cpp_wrapper.write_text('#!/bin/sh\nexec ' + shlex.join(cpp_command) + ' "$@"\n', newline='\n')
        script += ' && chmod +x ' + shlex.quote(convert(profile / cpp))
        script += ' && cp ' + shlex.quote(convert(cpp_wrapper)) + ' "$work/bin/cpp0" && chmod +x "$work/bin/cpp0"'
    specs = f'lib/gcc-lib/ee/{version}/specs'
    if specs in files:
        script += ' && cp ' + shlex.quote(convert(profile / specs)) + ' "$work/bin/specs"'
    script += ' && cp ' + shlex.quote(convert(source)) + ' "$work/source.c"'
    script += ' && cp -R ' + shlex.quote(convert(ROOT / 'include')) + ' "$work/include"'
    script += ' && export TMPDIR="$work"'
    script += ' && printf "' + label + ' scratch: %s\n" "$work" >&2'
    script += ' && cd "$work"'
    script += ' && ' + shlex.join(compiler) + ' -B"$work/bin/" ' + shlex.join(flags)
    script += ' -I"$work/include" -S "$work/source.c" -o "$work/output.s"'
    script += ' && cp "$work/output.s" ' + shlex.quote(convert(output))
    host = ['wsl.exe', '-d', distro, '-e', '/bin/sh', '-c'] if os.name == 'nt' else ['/bin/sh', '-c']
    return subprocess.run([*host, script], cwd=ROOT).returncode


def main() -> int:
    if len(sys.argv) < 3:
        sys.exit('usage: ee32_040921.py SOURCE.c OUTPUT.s [compiler flags...]')
    try:
        return compile_source(Path(sys.argv[1]).resolve(), Path(sys.argv[2]).resolve(), sys.argv[3:])
    except (OSError, ValueError) as error:
        sys.exit(str(error))


if __name__ == '__main__':
    raise SystemExit(main())

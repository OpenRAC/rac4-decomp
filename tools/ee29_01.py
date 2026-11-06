"""Run the pinned, isolated Linux EE-GCC 2.9-ee-991111-01 C compiler.

This transports compiler execution only; it never edits compiler output.
Windows uses headless WSL. See docs/TOOLCHAIN.md for the required profile.
"""
from __future__ import annotations

import hashlib
import os
from pathlib import Path, PureWindowsPath
import shlex
import subprocess
import sys

ROOT = Path(__file__).resolve().parent.parent
VERSION = '2.9-ee-991111-01'
FILES = {
    'bin/ee-gcc': '64d0a50fef499da0b98177eb5e79e41dfb066ad44246b137c78a266ef97ee265',
    f'lib/gcc-lib/ee/{VERSION}/cc1': 'b9aef69f93efb949f15ea58189e8eef4a002b9fe4de5d3fcf89c34e1244ec026',
    f'lib/gcc-lib/ee/{VERSION}/cpp': 'f85a54d241e019993fa7a06285d3677856b3b431e10318a587ab029373c603d7',
    'runtime/ld-2.3.6.so': 'd5a16aee4a04db7fa27a5c071a0bef62002ee679bf5ecce51e383003cf840fd8',
    'runtime/libc.so.6': '7b091aee7173e3a7cbddc6630fa6b0d0106944b5618b0b27c2c058ea9c3d92eb',
}


def wsl_path(path: str, distro: str) -> str:
    p = PureWindowsPath(path)
    if not p.drive or p.drive.startswith('\\'):
        raise ValueError('EE29-01 WSL execution requires a local drive path')
    mount = '/mnt/host' if distro == 'docker-desktop' else '/mnt'
    return '/'.join([mount, p.drive[0].lower(), *p.parts[1:]])


def compile_source(source: Path, output: Path, flags: list[str]) -> int:
    profile = Path(os.environ.get('EE29_01_ROOT', ROOT / 'build/isolated/ee-gcc2.9-991111-01')).resolve()
    for relative, expected in FILES.items():
        p = profile / relative
        if not p.is_file() or hashlib.sha256(p.read_bytes()).hexdigest() != expected:
            raise ValueError(f'@ee29-01 missing or unverified profile file: {p} (docs/TOOLCHAIN.md)')

    distro = os.environ.get('EE29_01_WSL_DISTRO', 'docker-desktop')
    convert = (lambda p: wsl_path(str(p.resolve()), distro)) if os.name == 'nt' else (lambda p: str(p.resolve()))
    # The driver execs cc1/cpp by name. Private wrappers give those original
    # binaries their bundled loader without installing anything in /lib.
    wrappers = output.parent / (output.stem + '_ee29_01')
    wrappers.mkdir(parents=True, exist_ok=True)
    loader = convert(profile / 'runtime/ld-2.3.6.so')
    runtime = convert(profile / 'runtime')
    for program in ('cc1', 'cpp'):
        command = [loader, '--library-path', runtime, convert(profile / f'lib/gcc-lib/ee/{VERSION}/{program}')]
        (wrappers / program).write_text('#!/bin/sh\nexec ' + shlex.join(command) + ' "$@"\n', newline='\n')
    compiler = [loader, '--library-path', runtime, convert(profile / 'bin/ee-gcc'),
                '-B' + convert(wrappers) + '/', *flags]
    executable = [convert(profile / 'bin/ee-gcc'), loader,
                  convert(profile / f'lib/gcc-lib/ee/{VERSION}/cc1'),
                  convert(profile / f'lib/gcc-lib/ee/{VERSION}/cpp'),
                  convert(wrappers / 'cc1'), convert(wrappers / 'cpp')]
    script = 'cd ' + shlex.quote(convert(ROOT)) + ' && chmod +x ' + shlex.join(executable)
    # Old 32-bit glibc stat() cannot represent the large inode numbers of
    # WSL's Windows mounts. Compile byte-identical inputs on native /tmp,
    # then copy the emitted assembly back without altering it.
    script += ' && work=$(mktemp -d /tmp/rac4-ee29-01.XXXXXXXX)'
    script += ' && cp ' + shlex.quote(convert(source)) + ' "$work/source.c"'
    script += ' && cp -R ' + shlex.quote(convert(ROOT / 'include')) + ' "$work/include"'
    script += ' && export TMPDIR="$work"'
    script += ' && printf "ee29-01 scratch: %s\\n" "$work" >&2'
    script += ' && ' + shlex.join(compiler) + ' -I"$work/include" -S "$work/source.c" -o "$work/output.s"'
    script += ' && cp "$work/output.s" ' + shlex.quote(convert(output))
    host = ['wsl.exe', '-d', distro, '-e', '/bin/sh', '-c'] if os.name == 'nt' else ['/bin/sh', '-c']
    return subprocess.run([*host, script], cwd=ROOT).returncode


def main() -> int:
    if len(sys.argv) < 3:
        sys.exit('usage: ee29_01.py SOURCE.c OUTPUT.s [compiler flags...]')
    try:
        return compile_source(Path(sys.argv[1]).resolve(), Path(sys.argv[2]).resolve(), sys.argv[3:])
    except (OSError, ValueError) as error:
        sys.exit(str(error))


if __name__ == '__main__':
    raise SystemExit(main())

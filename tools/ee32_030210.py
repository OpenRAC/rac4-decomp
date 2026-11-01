"""Run the pinned original EE-GCC 3.2 beta2 on Windows, without output edits."""
from __future__ import annotations

import hashlib
import os
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parent.parent
VERSION = '3.2-beta2-ee-030210'
FILES = {
    'bin/ee-gcc.exe': '2873e3a3ec5fe9188677445385ad5fc7be7fc24fee10296b677cbae679e2503e',
    f'lib/gcc-lib/ee/{VERSION}/cc1.exe': 'fd46a0564787b2e7bb9effc094d77a86c7f7ac1a511c0149aeb416376b63fd79',
    f'lib/gcc-lib/ee/{VERSION}/cpp0.exe': '1f1cf0066429847bb403563d3f42f98d655f64ba05db75a267d2b4c6d070cec8',
    f'lib/gcc-lib/ee/{VERSION}/specs': 'de08511f81d6c9fb829c1aad69d12447a4ce874865a9b70aaebe8bfeb6ecc44f',
    'dll/cygwin1.dll': '84b6266a2e3eee856ef247277040065c4ede7e504932a3a83f85d2a11b7713ed',
    'dll/cygintl-2.dll': 'ca618177d22da0199b73183197fdd4ff4b103deba3aebef7cc5d8a02bd92a835',
    'dll/cygiconv-2.dll': '3dcd9023abf5260b675d5bf68003fb71b20d036a7893dc17d295e8f47f36f1e7',
}


def compile_source(source: Path, output: Path, flags: list[str]) -> int:
    profile = Path(os.environ.get('EE32_030210_ROOT', ROOT / 'build/isolated/ee-gcc3.2-030210-beta2')).resolve()
    for relative, expected in FILES.items():
        path = profile / relative
        if not path.is_file() or hashlib.sha256(path.read_bytes()).hexdigest() != expected:
            raise ValueError(f'@ee32-030210 missing or unverified profile file: {path} (docs/TOOLCHAIN.md)')
    if os.name != 'nt':
        raise ValueError('@ee32-030210 currently requires native Windows; no alternate runtime is selected')
    import ctypes
    # Inherited by the compiler children; keep loader/crash diagnostics in
    # the redirected logs instead of opening system error dialogs.
    old_mode = ctypes.windll.kernel32.SetErrorMode(0x8003)
    env = os.environ.copy()
    env['PATH'] = str(profile / 'dll') + os.pathsep + env.get('PATH', '')
    command = [str(profile / 'bin/ee-gcc.exe'),
               '-B' + (profile / f'lib/gcc-lib/ee/{VERSION}').as_posix() + '/',
               *flags, '-I' + (ROOT / 'include').as_posix(),
               '-S', source.as_posix(), '-o', output.as_posix()]
    try:
        return subprocess.run(command, cwd=ROOT, env=env,
                              creationflags=subprocess.CREATE_NO_WINDOW).returncode
    finally:
        ctypes.windll.kernel32.SetErrorMode(old_mode)


def main() -> int:
    if len(sys.argv) < 3:
        sys.exit('usage: ee32_030210.py SOURCE.c OUTPUT.s [compiler flags...]')
    try:
        return compile_source(Path(sys.argv[1]).resolve(), Path(sys.argv[2]).resolve(), sys.argv[3:])
    except (OSError, ValueError) as error:
        sys.exit(str(error))


if __name__ == '__main__':
    raise SystemExit(main())

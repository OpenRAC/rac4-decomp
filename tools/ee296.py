"""Original EE-GCC 2.96 profile; distinct from the mislabeled local SN directory."""
import os
from pathlib import Path
import sys

import ee32_040921

ROOT = Path(__file__).resolve().parent.parent
VERSION = '2.96-ee-001003-1'
FILES = {
    'bin/ee-gcc': 'b8c284d16c9c0a0e8788e9522c46881e224ad01fa1c732aed43f821cc32f168b',
    f'lib/gcc-lib/ee/{VERSION}/cc1': '59ec92b3f9f3513e0633331af304733e3094de30884e662a8cb584a51c1c42b5',
    f'lib/gcc-lib/ee/{VERSION}/cpp0': 'f6f6b598f39649edfe171d6da8c7f91d07f2b87c2aeeffffbc5f566bfb1a39a9',
    'runtime/ld-2.3.6.so': ee32_040921.FILES['runtime/ld-2.3.6.so'],
    'runtime/libc.so.6': ee32_040921.FILES['runtime/libc.so.6'],
}


def compile_source(source: Path, output: Path, flags: list[str]) -> int:
    profile = Path(os.environ.get('EE296_ROOT', ROOT / 'build/isolated/ee-gcc2.96'))
    distro = os.environ.get('EE296_WSL_DISTRO', 'docker-desktop')
    return ee32_040921.compile_source(source, output, flags, version=VERSION,
                                      files=FILES, profile=profile, distro=distro, label='ee296')


if __name__ == '__main__':
    if len(sys.argv) < 3:
        sys.exit('usage: ee296.py SOURCE.c OUTPUT.s [compiler flags...]')
    try:
        sys.exit(compile_source(Path(sys.argv[1]).resolve(), Path(sys.argv[2]).resolve(), sys.argv[3:]))
    except (OSError, ValueError) as error:
        sys.exit(str(error))

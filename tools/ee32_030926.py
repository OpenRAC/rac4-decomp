"""Original EE-GCC 3.2-ee-030926 profile using the shared unchanged-output transport."""
import os
from pathlib import Path
import sys

import ee32_040921

ROOT = Path(__file__).resolve().parent.parent
VERSION = '3.2-ee-030926'
FILES = {
    'bin/ee-gcc': '8ba17b0f2cbcc87b31bb164766bc3e7e340f714adfb518bc4634a6f1ffda8951',
    f'lib/gcc-lib/ee/{VERSION}/cc1': 'da4fec4d48d91e62fd968f76acb16981dd8131d02f27c1b7559f0e903b590eb6',
    f'lib/gcc-lib/ee/{VERSION}/cpp0': '2d1a4b260e143a8b467bb7609cb3fd60ae541174ffff78d922feb2d7fbb0e218',
    f'lib/gcc-lib/ee/{VERSION}/specs': '17a1f6cd0d5bbb4d80bb77726e879eda08bc19c59ec2df5e77bab99c7cc1a3fa',
    'runtime/ld-2.3.6.so': ee32_040921.FILES['runtime/ld-2.3.6.so'],
    'runtime/libc.so.6': ee32_040921.FILES['runtime/libc.so.6'],
}


def compile_source(source: Path, output: Path, flags: list[str]) -> int:
    profile = Path(os.environ.get('EE32_030926_ROOT', ROOT / 'build/isolated/ee-gcc3.2-030926'))
    distro = os.environ.get('EE32_030926_WSL_DISTRO', 'docker-desktop')
    return ee32_040921.compile_source(source, output, flags, version=VERSION,
                                      files=FILES, profile=profile, distro=distro)


if __name__ == '__main__':
    if len(sys.argv) < 3:
        sys.exit('usage: ee32_030926.py SOURCE.c OUTPUT.s [compiler flags...]')
    try:
        sys.exit(compile_source(Path(sys.argv[1]).resolve(), Path(sys.argv[2]).resolve(), sys.argv[3:]))
    except (OSError, ValueError) as error:
        sys.exit(str(error))

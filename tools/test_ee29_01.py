"""Path transport and profile validation for the isolated compiler route."""
import tempfile
from pathlib import Path
import unittest
from unittest.mock import patch

import ee29_01


class IsolatedCompilerTests(unittest.TestCase):
    def test_docker_desktop_mount_and_spaces(self):
        self.assertEqual(ee29_01.wsl_path(r'D:\My Project\try.c', 'docker-desktop'),
                         '/mnt/host/d/My Project/try.c')

    def test_standard_wsl_drive_mount(self):
        self.assertEqual(ee29_01.wsl_path(r'C:\work\try.c', 'Ubuntu'), '/mnt/c/work/try.c')

    def test_unc_profile_path_is_rejected(self):
        with self.assertRaises(ValueError):
            ee29_01.wsl_path(r'\\server\share\try.c', 'docker-desktop')

    def test_missing_or_modified_profile_stops_before_compiler_execution(self):
        with tempfile.TemporaryDirectory() as temp:
            with patch.dict(ee29_01.os.environ, {'EE29_01_ROOT': temp}):
                with patch.object(ee29_01.subprocess, 'run') as run:
                    with self.assertRaisesRegex(ValueError, 'missing or unverified'):
                        ee29_01.compile_source(Path('try.c'), Path('out.s'), [])
                    path = Path(temp) / 'bin/ee-gcc'
                    path.parent.mkdir()
                    path.write_bytes(b'modified compiler')
                    with self.assertRaisesRegex(ValueError, 'missing or unverified'):
                        ee29_01.compile_source(Path('try.c'), Path('out.s'), [])
                    run.assert_not_called()


if __name__ == '__main__':
    unittest.main()

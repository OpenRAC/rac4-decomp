"""Additional isolated profile guards and native child-process environment."""
import hashlib
import os
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

import ee32_030210
import ee32_030926
import ee296


class AdditionalProfiles(unittest.TestCase):
    def test_both_profiles_reject_modified_inputs_before_execution(self):
        for module, env_name in ((ee32_030210, 'EE32_030210_ROOT'),
                                  (ee32_030926, 'EE32_030926_ROOT'),
                                  (ee296, 'EE296_ROOT')):
            with self.subTest(profile=env_name), tempfile.TemporaryDirectory() as temp:
                root = Path(temp)
                (root / 'specs').write_bytes(b'original')
                expected = {'specs': hashlib.sha256(b'original').hexdigest()}
                (root / 'specs').write_bytes(b'modified')
                with patch.dict(os.environ, {env_name: temp}), patch.object(module, 'FILES', expected):
                    with patch('subprocess.run') as run:
                        with self.assertRaisesRegex(ValueError, 'missing or unverified'):
                            module.compile_source(root / 'source.c', root / 'out.s', [])
                        run.assert_not_called()

    @unittest.skipUnless(os.name == 'nt', 'native Windows profile')
    def test_beta_private_dll_path_does_not_mutate_parent_environment(self):
        with tempfile.TemporaryDirectory(prefix='ee32 beta ') as temp:
            root = Path(temp)
            old_path = os.environ.get('PATH')
            with patch.dict(os.environ, {'EE32_030210_ROOT': temp}), patch.object(ee32_030210, 'FILES', {}):
                with patch('ctypes.windll.kernel32.SetErrorMode', return_value=7) as mode:
                    with patch.object(ee32_030210.subprocess, 'run') as run:
                        run.return_value.returncode = 5
                        self.assertEqual(ee32_030210.compile_source(root / 'source.c', root / 'out.s', ['-DNAME=two words']), 5)
                        args = run.call_args.args[0]
                        self.assertIn('-DNAME=two words', args)
                        self.assertEqual(args[-4:], ['-S', (root / 'source.c').as_posix(), '-o', (root / 'out.s').as_posix()])
                        env = run.call_args.kwargs['env']
                        self.assertTrue(env['PATH'].startswith(str(root / 'dll') + os.pathsep))
                        self.assertEqual(os.environ.get('PATH'), old_path)
                        self.assertEqual(run.call_args.kwargs['creationflags'], ee32_030210.subprocess.CREATE_NO_WINDOW)
                        self.assertEqual(mode.call_args_list[-1].args, (7,))


if __name__ == '__main__':
    unittest.main()

"""Fail-closed profile validation and native-storage command transport."""
import hashlib
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

import ee32_040921


class IsolatedCompilerTests(unittest.TestCase):
    def test_modified_runtime_stops_before_any_execution(self):
        with tempfile.TemporaryDirectory() as temp:
            profile = Path(temp)
            files = {'bin/ee-gcc': b'driver', 'runtime/libc.so.6': b'runtime'}
            expected = {}
            for relative, body in files.items():
                path = profile / relative
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(body)
                expected[relative] = hashlib.sha256(body).hexdigest()
            (profile / 'runtime/libc.so.6').write_bytes(b'changed')
            with patch.dict(ee32_040921.os.environ, {'EE32_040921_ROOT': temp}):
                with patch.object(ee32_040921, 'FILES', expected):
                    with patch.object(ee32_040921.subprocess, 'run') as run:
                        with self.assertRaisesRegex(ValueError, 'missing or unverified'):
                            ee32_040921.compile_source(profile / 'source.c', profile / 'out.s', [])
                        run.assert_not_called()

    def test_driver_search_and_inputs_use_native_storage(self):
        with tempfile.TemporaryDirectory(prefix='ee32 profile ') as temp:
            profile = Path(temp)
            output = profile / 'result.s'
            with patch.dict(ee32_040921.os.environ, {'EE32_040921_ROOT': temp}):
                with patch.object(ee32_040921, 'FILES', {}):
                    with patch.object(ee32_040921.subprocess, 'run') as run:
                        run.return_value.returncode = 9
                        result = ee32_040921.compile_source(profile / 'source.c', output, ['-DNAME=two words'])
                        self.assertEqual(result, 9)
                        script = run.call_args.args[0][-1]
                        self.assertIn('-B"$work/bin/"', script)
                        self.assertIn('"$work/bin/cc1"', script)
                        self.assertIn("'-DNAME=two words'", script)
                        self.assertIn(' -S "$work/source.c" -o "$work/output.s"', script)
                        self.assertIn(' && cp "$work/output.s" ', script)
                        wrapper = output.parent / (output.stem + '_ee32_040921') / 'cc1'
                        self.assertTrue(wrapper.read_text().endswith(' "$@"\n'))


if __name__ == '__main__':
    unittest.main()

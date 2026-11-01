"""Behavior tests for tools/cc.sh, using isolated fake tool drivers."""
from __future__ import annotations

import os
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parent
BASH = os.environ.get("RAC4_TEST_BASH") or (str(Path(os.environ.get("ProgramFiles", "C:/Program Files")) / "Git/bin/bash.exe") if os.name == "nt" else shutil.which("bash"))

FAKE_TOOLS = r'''
TRACE="$TRACE_PATH"
export TRACE
wine() {
    printf 'wine' >> "$TRACE"
    for arg in "$@"; do printf '\t%s' "$arg" >> "$TRACE"; done
    printf '\n' >> "$TRACE"
    local prev= output= arg
    for arg in "$@"; do
        if [ "$prev" = '-o' ]; then output=$arg; break; fi
        prev=$arg
    done
    if [ -n "$output" ]; then : > "$output"; fi
}
python() {
    printf 'python' >> "$TRACE"
    for arg in "$@"; do printf '\t%s' "$arg" >> "$TRACE"; done
    printf '\n' >> "$TRACE"
    local last= arg
    for arg in "$@"; do last=$arg; done
    case "$last" in
        *_fixed.s) : > "$last" ;;
    esac
}
export -f wine python
'''


@unittest.skipUnless(BASH and Path(BASH).is_file(), "Bash required; set RAC4_TEST_BASH if needed")
class CompilerRouteTests(unittest.TestCase):
    def setUp(self) -> None:
        self.temp = tempfile.TemporaryDirectory(prefix="rac4-cc-route-")
        self.root = Path(self.temp.name)
        (self.root / "tools").mkdir()
        shutil.copyfile(ROOT / "cc.sh", self.root / "tools" / "cc.sh")
        (self.root / "include").mkdir()
        (self.root / "build" / "obj").mkdir(parents=True)
        self.trace = self.root / "trace.tsv"
        self._touch("toolchain/sn-prodg-3.01/usr/local/sce/ee/gcc/bin/ee-gcc2953.exe")
        self._touch("toolchain/sn-prodg-24/local/sce/ee/gcc/bin/ee-gcc.exe")
        self._touch("toolchain/sn-prodg-24/local/sce/ee/gcc/lib/gcc-lib/ee/2.9-ee-991111/stamp")
        for program, version in (('ee-gcc2953.exe', '2.95.3'), ('ee-gcc295.exe', '2.95.2')):
            self._touch('toolchain/sn-prodg-24/local/sce/ee/gcc/bin/' + program)
            for backend in ('cc1.exe', 'cpp.exe'):
                self._touch('toolchain/sn-prodg-24/local/sce/ee/gcc/lib/gcc-lib/ee/' + version + '/' + backend)
        for backend in ('cc1.exe', 'cpp.exe'):
            self._touch('toolchain/sn-prodg-24/local/sce/ee/gcc/lib/gcc-lib/ee/2.96-ee-001003-1/' + backend)

    def tearDown(self) -> None:
        self.temp.cleanup()

    def _touch(self, relative: str) -> None:
        path = self.root / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.touch()

    def run_cc(self, *args: str) -> subprocess.CompletedProcess[str]:
        script = FAKE_TOOLS + '\n"$BASH" tools/cc.sh "$@"'
        env = os.environ.copy()
        env["TRACE_PATH"] = self.trace.as_posix()
        return subprocess.run(
            [BASH, "-c", script, "cc-route-test", *args], cwd=self.root, env=env,
            text=True, capture_output=True, check=False,
        )

    def calls(self) -> list[list[str]]:
        return [line.split("\t") for line in self.trace.read_text(encoding="utf-8").splitlines()]

    def test_default_sn_route_keeps_fixups(self) -> None:
        result = self.run_cc("source.c", "build/obj/default.o", "-DVALUE=one two")
        self.assertEqual(result.returncode, 0, result.stderr)
        calls = self.calls()
        self.assertEqual([call[0] for call in calls], ["wine", "python", "python", "python", "wine", "python", "wine"])
        self.assertIn("-DVALUE=one two", calls[0])
        self.assertIn("tools/ps2eeas_dli.py", calls[1])
        self.assertIn("tools/ps2eeas_lis.py", calls[2])
        self.assertIn("tools/ps2eeas_sdata.py", calls[3])
        self.assertIn("tools/ps2eeas_nops.py", calls[5])
        self.assertEqual(calls[4][2], "-c")
        self.assertEqual(calls[6][2], "-c")
        self.assertNotIn("-DVALUE=one two", calls[4])
        self.assertNotIn("-DVALUE=one two", calls[6])
        self.assertTrue((self.root / "build/obj/default.o").exists())

    def test_lit4_marker_skips_lis_and_is_not_passed_on(self) -> None:
        result = self.run_cc("source.c", "build/obj/lit4.o", "@lit4", "-DVALUE=one two")
        self.assertEqual(result.returncode, 0, result.stderr)
        calls = self.calls()
        self.assertEqual([call[0] for call in calls], ["wine", "python", "python", "wine", "python", "wine"])
        self.assertNotIn("@lit4", calls[0])
        self.assertIn("-DVALUE=one two", calls[0])
        self.assertFalse(any("tools/ps2eeas_lis.py" in call for call in calls))

    def test_lit4_marker_does_not_reach_isolated_compiler(self) -> None:
        result = self.run_cc("source.c", "build/obj/lit4-ee296.o", "@ee296", "@lit4", "-O2", "-G0")
        self.assertEqual(result.returncode, 0, result.stderr)
        calls = self.calls()
        self.assertEqual([call[0] for call in calls], ["python", "wine"])
        self.assertFalse(any("@lit4" in call for call in calls))
        self.assertFalse(any("ps2eeas_" in arg for call in calls for arg in call))

    def test_explicit_assembler_options_reach_both_sn_passes(self) -> None:
        options = ["-Wa,-G0", "-Wa,-I,path with spaces"]
        result = self.run_cc("source.c", "build/obj/asflags.o",
                             "-G0", options[0], "-mno-split-addresses", options[1])
        self.assertEqual(result.returncode, 0, result.stderr)
        calls = self.calls()
        for index in (4, 6):
            call = calls[index]
            self.assertEqual(call[2:call.index("-c")], options)
            self.assertNotIn("-G0", call)
            self.assertNotIn("-mno-split-addresses", call)
        self.assertEqual([arg for arg in calls[0] if arg.startswith("-Wa,")], options)

    def test_explicit_assembler_options_do_not_change_ee29_assembler_route(self) -> None:
        result = self.run_cc("source.c", "build/obj/asflags29.o", "@ee29", "-Wa,-G0")
        self.assertEqual(result.returncode, 0, result.stderr)
        calls = self.calls()
        self.assertEqual(len(calls), 2)
        self.assertIn("-Wa,-G0", calls[0])
        self.assertNotIn("-Wa,-G0", calls[1])
        self.assertEqual(calls[1][2], "-c")

    def test_ee29_01_uses_isolated_compiler_without_rewriting_its_output(self) -> None:
        result = self.run_cc("source.c", "build/obj/ee29_01.o",
                             "@ee29-01", "-O2", "-G0", "-Wa,-G0")
        self.assertEqual(result.returncode, 0, result.stderr)
        calls = self.calls()
        self.assertEqual([call[0] for call in calls], ["python", "wine"])
        self.assertEqual(calls[0][1:3], ["tools/ee29_01.py", "source.c"])
        self.assertEqual(calls[0][-3:], ["-O2", "-G0", "-Wa,-G0"])
        self.assertEqual(calls[1][2:4], ["-Wa,-G0", "-c"])
        self.assertFalse(any("ps2eeas_" in arg for call in calls for arg in call))

    def test_conflicting_compiler_profiles_are_rejected_before_execution(self) -> None:
        result = self.run_cc("source.c", "build/obj/conflict.o", "@ee29", "@ee29-01")
        self.assertNotEqual(result.returncode, 0)
        self.assertIn('choose either @ee29 or @ee29-01', result.stderr)
        self.assertFalse(self.trace.exists())

    def test_ee32_040921_uses_isolated_compiler_without_output_fixups(self) -> None:
        result = self.run_cc('source.c', 'build/obj/ee32.o',
                             '@ee32-040921', '-O2', '-G0', '-Wa,-G0')
        self.assertEqual(result.returncode, 0, result.stderr)
        calls = self.calls()
        self.assertEqual([call[0] for call in calls], ['python', 'wine'])
        self.assertEqual(calls[0][1:3], ['tools/ee32_040921.py', 'source.c'])
        self.assertEqual(calls[0][-3:], ['-O2', '-G0', '-Wa,-G0'])
        self.assertEqual(calls[1][2:4], ['-Wa,-G0', '-c'])
        self.assertFalse(any('ps2eeas_' in arg for call in calls for arg in call))

    def test_ee32_conflicts_are_rejected_before_execution(self) -> None:
        for other in ('@ee29', '@ee29-01'):
            with self.subTest(other=other):
                result = self.run_cc('source.c', 'build/obj/conflict32.o', other, '@ee32-040921')
                self.assertNotEqual(result.returncode, 0)
                self.assertIn('choose only one compiler profile', result.stderr)
                self.assertFalse(self.trace.exists())

    def test_older_sn_profiles_keep_fixups_and_omit_unsupported_stack_flag(self) -> None:
        for marker, program, version in (('@sn114', 'ee-gcc2953.exe', '2.95.3'),
                                         ('@sn274', 'ee-gcc295.exe', '2.95.2'),
                                         ('@sn107', 'ee-gcc2953.exe', '2.96-ee-001003-1')):
            with self.subTest(marker=marker):
                self.trace.unlink(missing_ok=True)
                result = self.run_cc('source.c', 'build/obj/older.o', marker, '-Wa,-G0')
                self.assertEqual(result.returncode, 0, result.stderr)
                calls = self.calls()
                self.assertTrue(calls[0][1].endswith('/' + program))
                self.assertIn('-Btoolchain/sn-prodg-24/local/sce/ee/gcc/lib/gcc-lib/ee/' + version + '/', calls[0])
                self.assertNotIn('-fopt-stack', calls[0])
                self.assertNotIn(marker, calls[0])
                if marker == '@sn107':
                    self.assertIn('-specs=toolchain/sn-prodg-24/local/sce/ee/gcc/lib/gcc-lib/ee/2.95.3/specs', calls[0])
                self.assertEqual([c[0] for c in calls], ['wine', 'python', 'python', 'python', 'wine', 'python', 'wine'])
                for i in (4, 6):
                    self.assertTrue(calls[i][1].endswith('/ee-gcc2953.exe'))
                    self.assertIn('-Wa,-G0', calls[i])

    def test_older_sn_missing_backend_does_not_fall_back_to_another_compiler(self) -> None:
        (self.root / 'toolchain/sn-prodg-24/local/sce/ee/gcc/lib/gcc-lib/ee/2.95.3/cc1.exe').unlink()
        result = self.run_cc('source.c', 'build/obj/missing114.o', '@sn114')
        self.assertNotEqual(result.returncode, 0)
        self.assertIn('older SN backend or preprocessor not found', result.stderr)
        self.assertFalse(self.trace.exists())

    def test_additional_ee32_profiles_use_original_emitters_and_sn_assembler(self) -> None:
        for marker, helper in (('@ee32-030210', 'ee32_030210.py'),
                                ('@ee32-030926', 'ee32_030926.py'),
                                ('@ee296', 'ee296.py')):
            with self.subTest(marker=marker):
                self.trace.unlink(missing_ok=True)
                result = self.run_cc('source.c', 'build/obj/ee32more.o', marker, '-O2', '-G0', '-Wa,-G0')
                self.assertEqual(result.returncode, 0, result.stderr)
                calls = self.calls()
                self.assertEqual([c[0] for c in calls], ['python', 'wine'])
                self.assertEqual(calls[0][1], 'tools/' + helper)
                self.assertEqual(calls[0][-3:], ['-O2', '-G0', '-Wa,-G0'])
                self.assertEqual(calls[1][2:4], ['-Wa,-G0', '-c'])
                self.assertFalse(any('ps2eeas_' in a for c in calls for a in c))

    def test_additional_ee32_profile_conflicts_stop_before_execution(self) -> None:
        for profiles in (('@ee32-030210', '@ee32-030926'),
                         ('@ee32-030210', '@ee32-040921'),
                         ('@ee32-030926', '@ee29-01'),
                         ('@ee296', '@sn107')):
            with self.subTest(profiles=profiles):
                result = self.run_cc('source.c', 'build/obj/conflictmore.o', *profiles)
                self.assertNotEqual(result.returncode, 0)
                self.assertIn('choose only one compiler profile', result.stderr)
                self.assertFalse(self.trace.exists())

    def test_ee29_route_uses_pinned_compiler_and_assembler_without_fixups(self) -> None:
        result = self.run_cc("source.c", "build/obj/ee29.o", "@ee29", "-O2", "-G2", "-DNAME=two words")
        self.assertEqual(result.returncode, 0, result.stderr)
        calls = self.calls()
        self.assertEqual([call[0] for call in calls], ["wine", "wine"])
        self.assertIn("toolchain/sn-prodg-24/local/sce/ee/gcc/bin/ee-gcc.exe", calls[0])
        self.assertIn("-Btoolchain/sn-prodg-24/local/sce/ee/gcc/lib/gcc-lib/ee/2.9-ee-991111/", calls[0])
        self.assertIn("-DNAME=two words", calls[0])
        self.assertTrue(calls[1][1].endswith("/ee-gcc2953.exe"))
        self.assertFalse(any("ps2eeas_" in arg for call in calls for arg in call))
        self.assertTrue((self.root / "build/obj/ee29.o").exists())

    def test_marker_alone_uses_documented_default_flags(self) -> None:
        result = self.run_cc("source.c", "build/obj/default29.o", "@ee29")
        self.assertEqual(result.returncode, 0, result.stderr)
        calls = self.calls()
        self.assertEqual(calls[0][0], "wine")
        self.assertEqual(calls[0][calls[0].index("-Btoolchain/sn-prodg-24/local/sce/ee/gcc/lib/gcc-lib/ee/2.9-ee-991111/") + 1 :][:2], ["-O2", "-G0"])

    def test_missing_pinned_library_path_has_actionable_error(self) -> None:
        shutil.rmtree(self.root / "toolchain/sn-prodg-24/local/sce/ee/gcc/lib/gcc-lib/ee/2.9-ee-991111")
        result = self.run_cc("source.c", "build/obj/missing.o", "@ee29")
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("@ee29 GCC library directory not found", result.stderr)
        self.assertFalse(self.trace.exists())

    def test_missing_ee29_compiler_names_expected_version(self) -> None:
        (self.root / "toolchain/sn-prodg-24/local/sce/ee/gcc/bin/ee-gcc.exe").unlink()
        result = self.run_cc("source.c", "build/obj/missing.o", "@ee29")
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("@ee29 compiler not found", result.stderr)
        self.assertIn("2.9-ee-991111", result.stderr)
        self.assertFalse(self.trace.exists())

    def test_missing_sn_assembler_driver_is_reported_on_ee29_route(self) -> None:
        (self.root / "toolchain/sn-prodg-3.01/usr/local/sce/ee/gcc/bin/ee-gcc2953.exe").unlink()
        result = self.run_cc("source.c", "build/obj/missing.o", "@ee29")
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("SN EE assembler driver not found", result.stderr)
        self.assertFalse(self.trace.exists())


if __name__ == "__main__":
    unittest.main(verbosity=2)

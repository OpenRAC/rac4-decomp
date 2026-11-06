"""Host/container launcher boundaries for the compiler batch driver."""
import os
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent))
import try_func


class CompileLauncherTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="rac4-compile-launcher-")
        self.root = Path(self.temp.name)
        self.work = self.root / "build/try/func_00100000"
        self.work.mkdir(parents=True)
        self.source = self.work / "candidate.c"
        self.source.write_text("void func_00100000(void) {}\n")
        self.obj = self.work / "candidate.o"
        self.jobs = [(self.source, self.obj, ["-O2", "-G8"])]
        self.relative_script = "build/try/func_00100000/compile.sh"

    def tearDown(self):
        self.temp.cleanup()

    def test_container_uses_host_bash_only_for_outer_launcher(self):
        for host_bash in ["/opt/homebrew/bin/bash", "/nix/store/example-bash-5.2/bin/bash"]:
            with self.subTest(host_bash=host_bash):
                host_path = host_bash.rpartition("/")[0]
                environment = {"PATH": host_path, "TASK_MARKER": "provided"}
                with patch.object(try_func, "ROOT", self.root), \
                        patch.object(try_func, "in_container", return_value=False), \
                        patch.object(try_func.shutil, "which", return_value=host_bash) as resolve, \
                        patch.object(try_func.subprocess, "run") as launch:
                    try_func.compile_all(self.jobs, self.work, env=environment)
                resolve.assert_called_once_with("bash", path=environment["PATH"])
                launch.assert_called_once_with(
                    [host_bash, "tools/docker/run.sh", "bash", self.relative_script],
                    cwd=self.root, env=environment,
                    stdout=try_func.subprocess.DEVNULL, stderr=try_func.subprocess.DEVNULL)
                self.assertEqual(environment, {"PATH": host_path, "TASK_MARKER": "provided"})

    def test_child_git_path_wins_over_ambient_windows_wsl_shadow(self):
        ambient = {"PATH": "C:/Windows/System32;C:/ambient/bin", "TASK_MARKER": "ambient"}
        environment = {"PATH": "C:/Program Files/Git/bin;C:/Windows/System32", "TASK_MARKER": "child"}
        git_bash = "C:/Program Files/Git/bin/bash.exe"
        wsl_bash = "C:/Windows/System32/bash.exe"

        def resolve(name, path=None):
            self.assertEqual(name, "bash")
            return git_bash if path == environment["PATH"] else wsl_bash

        with patch.dict(os.environ, ambient, clear=True), \
                patch.object(try_func, "ROOT", self.root), \
                patch.object(try_func, "in_container", return_value=True), \
                patch.object(try_func.shutil, "which", side_effect=resolve) as search, \
                patch.object(try_func.subprocess, "run") as launch:
            try_func.compile_all(self.jobs, self.work, env=environment)
        search.assert_called_once_with("bash", path=environment["PATH"])
        launch.assert_called_once_with(
            [git_bash, self.relative_script], cwd=self.root, env=environment,
            stdout=try_func.subprocess.DEVNULL, stderr=try_func.subprocess.DEVNULL)
        self.assertNotIn(wsl_bash, launch.call_args.args[0])

    def test_default_environment_and_lf_script_are_preserved(self):
        environment = {"PATH": "/host/bin:/usr/bin", "TASK_MARKER": "ambient"}
        host_bash = "/host/bin/bash"
        self.obj.write_bytes(b"stale object")
        with patch.dict(os.environ, environment, clear=True), \
                patch.object(try_func, "ROOT", self.root), \
                patch.object(try_func, "in_container", return_value=True), \
                patch.object(try_func.shutil, "which", return_value=host_bash) as resolve, \
                patch.object(try_func.subprocess, "run") as launch:
            try_func.compile_all(self.jobs, self.work)
        resolve.assert_called_once_with("bash", path=environment["PATH"])
        self.assertEqual(launch.call_args.kwargs["env"], environment)
        self.assertFalse(self.obj.exists())
        script = (self.work / "compile.sh").read_bytes()
        self.assertNotIn(b"\r", script)
        self.assertTrue(script.endswith(b"\n"))
        self.assertIn(b"bash tools/cc.sh build/try/func_00100000/candidate.c ", script)
        self.assertNotIn(b"\\", script)

    def test_child_path_controls_wine_availability(self):
        environment = {"PATH": "/child/bin"}

        def resolve(name, path=None):
            self.assertEqual(name, "wine")
            return None if path == environment["PATH"] else "/ambient/bin/wine"

        with patch.object(try_func.os, "name", "posix"), \
                patch.object(try_func.shutil, "which", side_effect=resolve) as search:
            self.assertFalse(try_func.in_container(environment))
        search.assert_called_once_with("wine", path=environment["PATH"])


if __name__ == "__main__":
    unittest.main(verbosity=2)

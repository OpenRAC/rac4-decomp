#!/usr/bin/env bash
# Compile a translation unit with the original compiler: SN GCC 2.95.3 by default, Sony EE GCC 2.9
# for translation units whose cflags contain the standalone token @ee29.
set -euo pipefail
cd "$(dirname "$0")/.."
if [ "$#" -lt 2 ]; then
    echo "usage: bash tools/cc.sh SRC.c OUT.o [extra compiler flags]" >&2
    exit 2
fi
src=$1
out=$2
shift 2
CC=toolchain/sn-prodg-3.01/usr/local/sce/ee/gcc/bin/ee-gcc2953.exe
export WINEDEBUG=-all
# Git Bash runs the 32-bit EXEs natively; other hosts use Wine when available.
WINE_CMD=()
if command -v wine >/dev/null 2>&1; then
    WINE_CMD=(wine)
fi
run_compiler() {
    "${WINE_CMD[@]}" "$@"
}
# The Python helpers are used only by the SN-output fixups below.
PY=python
[ -x venv/Scripts/python.exe ] && PY=venv/Scripts/python.exe
mkdir -p build/tmp
# GCC 2.95 takes its temporary directory from TMPDIR. Where it is unset, the
# Windows build falls back to C:\tmp, which need not exist or be writable.
export TMPDIR="$(cygpath -w "$PWD/build/tmp" 2>/dev/null || echo "$PWD/build/tmp")"
# Include the output path so parallel candidate builds do not share temp files.
tmp=build/tmp/$(echo "${out%.o}" | tr '/' '_')

# Keep argv as an array: remove only the marker token, retaining every other
# flag exactly as supplied (including values containing spaces).
ee29=0
lit4=0
flags29=()
for flag in "$@"; do
    if [ "$flag" = '@ee29' ]; then
        ee29=1
    elif [ "$flag" = '@lit4' ]; then
        # keep GNU as's .lit4 loads for li.s (skip tools/ps2eeas_lis.py)
        lit4=1
    else
        flags29+=("$flag")
    fi
done

if [ "$ee29" -eq 1 ]; then
    E29=toolchain/sn-prodg-24/local/sce/ee/gcc
    E29_CC=$E29/bin/ee-gcc.exe
    E29_LIB=$E29/lib/gcc-lib/ee/2.9-ee-991111
    if [ ! -f "$E29_CC" ]; then
        echo "error: @ee29 compiler not found: $E29_CC (expected Sony EE GCC 2.9-ee-991111)" >&2
        exit 1
    fi
    if [ ! -d "$E29_LIB" ]; then
        echo "error: @ee29 GCC library directory not found: $E29_LIB" >&2
        exit 1
    fi
    if [ ! -f "$CC" ]; then
        echo "error: SN EE assembler driver not found: $CC" >&2
        exit 1
    fi
    if [ "${#flags29[@]}" -eq 0 ]; then
        flags29=(-O2 -G0)
    fi
    run_compiler "$E29_CC" -B"$E29_LIB/" "${flags29[@]}" -Iinclude -S "$src" -o "$tmp.s"
    run_compiler "$CC" -c "$tmp.s" -o "$out"
    exit 0
fi

if [ ! -f "$CC" ]; then
    echo "error: SN EE compiler not found: $CC" >&2
    exit 1
fi
run_compiler "$CC" -O2 -G8 -fopt-stack -mno-check-zero-division ${flags29[@]+"${flags29[@]}"} -Iinclude -S "$src" -o "$tmp.s"
"$PY" tools/ps2eeas_dli.py "$tmp.s" "$tmp.s"
if [ "$lit4" -eq 0 ]; then
    "$PY" tools/ps2eeas_lis.py "$tmp.s" "$tmp.s"
fi
"$PY" tools/ps2eeas_sdata.py "$tmp.s" "$tmp.s"
run_compiler "$CC" -c "$tmp.s" -o "${tmp}_first.o"
"$PY" tools/ps2eeas_nops.py "$tmp.s" "${tmp}_first.o" "${tmp}_fixed.s"
run_compiler "$CC" -c "${tmp}_fixed.s" -o "$out"
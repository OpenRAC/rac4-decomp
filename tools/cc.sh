#!/usr/bin/env bash
# Compile with SN 1.36 by default; standalone profile markers opt a whole
# translation unit into an original compiler described in docs/TOOLCHAIN.md.
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
ee29_01=0
ee32_040921=0
ee32_030210=0
ee32_030926=0
sn114=0
sn274=0
sn107=0
ee296=0
flags29=()
sn_asflags=()
for flag in "$@"; do
    if [ "$flag" = '@ee29' ]; then
        ee29=1
    elif [ "$flag" = '@lit4' ]; then
        # Keep GNU as literal-pool loads rather than expanding li.s.
        lit4=1
    elif [ "$flag" = '@ee29-01' ]; then
        ee29_01=1
    elif [ "$flag" = '@ee32-040921' ]; then
        ee32_040921=1
    elif [ "$flag" = '@ee32-030210' ]; then
        ee32_030210=1
    elif [ "$flag" = '@ee32-030926' ]; then
        ee32_030926=1
    elif [ "$flag" = '@sn114' ]; then
        sn114=1
    elif [ "$flag" = '@sn274' ]; then
        sn274=1
    elif [ "$flag" = '@sn107' ]; then
        sn107=1
    elif [ "$flag" = '@ee296' ]; then
        ee296=1
    else
        flags29+=("$flag")
        # -S does not run the assembler. Preserve explicit assembler options
        # for both SN assembly passes without forwarding compiler-only flags.
        case "$flag" in
            -Wa,*) sn_asflags+=("$flag") ;;
        esac
    fi
done

if [ "$ee296" -eq 1 ]; then
    if [ "$((ee29 + ee29_01 + ee32_040921 + ee32_030210 + ee32_030926 + sn114 + sn274 + sn107))" -ne 0 ]; then
        echo 'error: choose only one compiler profile with @ee296' >&2
        exit 1
    fi
    if [ ! -f "$CC" ]; then
        echo "error: SN EE assembler driver not found: $CC" >&2
        exit 1
    fi
    if [ "${#flags29[@]}" -eq 0 ]; then
        flags29=(-O2 -G0)
    fi
    "$PY" tools/ee296.py "$src" "$tmp.s" "${flags29[@]}"
    run_compiler "$CC" "${sn_asflags[@]}" -c "$tmp.s" -o "$out"
    exit 0
fi

if [ "$((sn114 + sn274 + sn107))" -gt 0 ] && [ "$((ee29 + ee29_01 + ee32_040921 + ee32_030210 + ee32_030926 + sn114 + sn274 + sn107))" -ne 1 ]; then
    echo 'error: choose only one older SN compiler profile' >&2
    exit 1
fi

if [ "$ee32_030926" -eq 1 ]; then
    if [ "$((ee29 + ee29_01 + ee32_040921 + ee32_030210))" -ne 0 ]; then
        echo 'error: choose only one compiler profile with @ee32-030926' >&2
        exit 1
    fi
    if [ ! -f "$CC" ]; then
        echo "error: SN EE assembler driver not found: $CC" >&2
        exit 1
    fi
    if [ "${#flags29[@]}" -eq 0 ]; then
        flags29=(-O2 -G0)
    fi
    "$PY" tools/ee32_030926.py "$src" "$tmp.s" "${flags29[@]}"
    run_compiler "$CC" "${sn_asflags[@]}" -c "$tmp.s" -o "$out"
    exit 0
fi

if [ "$ee32_030210" -eq 1 ]; then
    if [ "$((ee29 + ee29_01 + ee32_040921))" -ne 0 ]; then
        echo 'error: choose only one compiler profile with @ee32-030210' >&2
        exit 1
    fi
    if [ ! -f "$CC" ]; then
        echo "error: SN EE assembler driver not found: $CC" >&2
        exit 1
    fi
    if [ "${#flags29[@]}" -eq 0 ]; then
        flags29=(-O2 -G0)
    fi
    "$PY" tools/ee32_030210.py "$src" "$tmp.s" "${flags29[@]}"
    run_compiler "$CC" "${sn_asflags[@]}" -c "$tmp.s" -o "$out"
    exit 0
fi

if [ "$ee32_040921" -eq 1 ]; then
    if [ "$ee29" -eq 1 ] || [ "$ee29_01" -eq 1 ]; then
        echo 'error: choose only one compiler profile: @ee29, @ee29-01 or @ee32-040921' >&2
        exit 1
    fi
    if [ ! -f "$CC" ]; then
        echo "error: SN EE assembler driver not found: $CC" >&2
        exit 1
    fi
    if [ "${#flags29[@]}" -eq 0 ]; then
        flags29=(-O2 -G0)
    fi
    "$PY" tools/ee32_040921.py "$src" "$tmp.s" "${flags29[@]}"
    run_compiler "$CC" "${sn_asflags[@]}" -c "$tmp.s" -o "$out"
    exit 0
fi

if [ "$ee29_01" -eq 1 ]; then
    if [ "$ee29" -eq 1 ]; then
        echo 'error: choose either @ee29 or @ee29-01, not both' >&2
        exit 1
    fi
    if [ ! -f "$CC" ]; then
        echo "error: SN EE assembler driver not found: $CC" >&2
        exit 1
    fi
    if [ "${#flags29[@]}" -eq 0 ]; then
        flags29=(-O2 -G0)
    fi
    "$PY" tools/ee29_01.py "$src" "$tmp.s" "${flags29[@]}"
    run_compiler "$CC" "${sn_asflags[@]}" -c "$tmp.s" -o "$out"
    exit 0
fi

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
compiler=$CC
compiler_prefix=()
compiler_defaults=(-O2 -G8 -fopt-stack -mno-check-zero-division)
if [ "$sn114" -eq 1 ] || [ "$sn274" -eq 1 ] || [ "$sn107" -eq 1 ]; then
    version=2.95.3
    program=ee-gcc2953.exe
    if [ "$sn274" -eq 1 ]; then
        version=2.95.2
        program=ee-gcc295.exe
    fi
    if [ "$sn107" -eq 1 ]; then
        version=2.96-ee-001003-1
    fi
    compiler=toolchain/sn-prodg-24/local/sce/ee/gcc/bin/$program
    compiler_prefix=(-Btoolchain/sn-prodg-24/local/sce/ee/gcc/lib/gcc-lib/ee/$version/)
    if [ "$sn107" -eq 1 ]; then
        # This directory's cc1/cpp are SN 1.07 despite its label. Use the
        # unchanged specs shipped with the public 1.07 compiler bundle.
        compiler_prefix+=(-specs=toolchain/sn-prodg-24/local/sce/ee/gcc/lib/gcc-lib/ee/2.95.3/specs)
    fi
    compiler_defaults=(-O2 -G8 -mno-check-zero-division)
    if [ ! -f "$compiler" ]; then
        echo "error: older SN compiler not found: $compiler" >&2
        exit 1
    fi
    backend=toolchain/sn-prodg-24/local/sce/ee/gcc/lib/gcc-lib/ee/$version
    if [ ! -f "$backend/cc1.exe" ] || [ ! -f "$backend/cpp.exe" ]; then
        echo "error: older SN backend or preprocessor not found: $backend" >&2
        exit 1
    fi
fi
run_compiler "$compiler" "${compiler_prefix[@]}" "${compiler_defaults[@]}" "${flags29[@]}" -Iinclude -S "$src" -o "$tmp.s"
"$PY" tools/ps2eeas_dli.py "$tmp.s" "$tmp.s"
if [ "$lit4" -eq 0 ]; then
    "$PY" tools/ps2eeas_lis.py "$tmp.s" "$tmp.s"
fi
"$PY" tools/ps2eeas_sdata.py "$tmp.s" "$tmp.s"
run_compiler "$CC" "${sn_asflags[@]}" -c "$tmp.s" -o "${tmp}_first.o"
"$PY" tools/ps2eeas_nops.py "$tmp.s" "${tmp}_first.o" "${tmp}_fixed.s"
run_compiler "$CC" "${sn_asflags[@]}" -c "${tmp}_fixed.s" -o "$out"

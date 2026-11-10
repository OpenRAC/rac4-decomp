#!/usr/bin/env bash
# Generate asm/ from your own baserom/SCUS_974.65 (never committed).
#   1. unpack the game image from the loader     (tools/unpack_wad.py)
#   2. split it into sections and rebuild an ELF (tools/split_image.py)
#   3. run splat on the ELF                      (config/splat.yaml)
set -euo pipefail
cd "$(dirname "$0")/.."

EXPECTED=aa91b1c3b9b1a244320c47580b77342ef9856e95
[ -f baserom/SCUS_974.65 ] || { echo "put your SCUS_974.65 in baserom/"; exit 1; }
# python3, not sha1sum: stock macOS has no sha1sum.
ACTUAL=$(python3 -c "import hashlib, sys; print(hashlib.sha1(open(sys.argv[1], 'rb').read()).hexdigest())" baserom/SCUS_974.65)
[ "$ACTUAL" = "$EXPECTED" ] || { echo "baserom/SCUS_974.65 has sha1 $ACTUAL, expected $EXPECTED"; exit 1; }

# the venv's python is venv/bin/python, or venv/Scripts/python.exe on Windows
VPY=venv/bin/python
[ -x venv/Scripts/python.exe ] && VPY=venv/Scripts/python.exe
if [ ! -x "$VPY" ]; then
    python3 -m venv venv 2>/dev/null || python -m venv venv
    [ -x venv/Scripts/python.exe ] && VPY=venv/Scripts/python.exe
    "$VPY" -m pip install -q -r requirements.txt
fi

"$VPY" tools/unpack_wad.py
"$VPY" tools/split_image.py
rm -rf asm
"$VPY" -m splat split config/splat.yaml

# Optional: the level overlays. Set OVERLAYS to a folder made by
# `wrenchbuild unpack GAME.iso -o DIR -g dl -r us` (docs/build/overlays.md).
if [ -n "${OVERLAYS:-}" ]; then
    "$VPY" tools/gen_overlay_asm.py "$OVERLAYS"
fi

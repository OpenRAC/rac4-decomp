"""
Helpers for working with the retail image: reading its sections and comparing
code with relocatable fields masked.

normalise(): opcode and registers are kept, everything a linker or relocation
can change is masked (j/jal targets, the immediate of `lui`, and of loads,
stores and adds that are not stack-relative). Two functions that are equal
after this masking are the same code at different addresses.
"""
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
J, JAL, LUI = 2, 3, 0x0F
MEM_OR_ADD = {0x08, 0x09, 0x0C, 0x0D, 0x0A, 0x0B, 0x20, 0x21, 0x23, 0x24, 0x25, 0x28,
              0x29, 0x2B, 0x31, 0x39, 0x37, 0x3F, 0x1E, 0x1F, 0x35, 0x3D, 0x27, 0x2F}


def normalise(code: bytes):
    out = []
    for (w,) in struct.iter_unpack("<I", code[: len(code) // 4 * 4]):
        op = w >> 26
        if op in (J, JAL):
            w = op << 26
        elif op == LUI:
            w &= 0xFFFF0000
        elif op in MEM_OR_ADD and ((w >> 21) & 31) != 29:
            w &= 0xFFFF0000
        out.append(w)
    return tuple(out)


# Relocation types whose field the linker fills in: R_MIPS_26 (j/jal target),
# R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16 and R_MIPS_LITERAL (immediate).
# Any other type: the word.
RELOC_FIELDS = {4: 0x03FFFFFF, 5: 0xFFFF, 6: 0xFFFF, 7: 0xFFFF, 8: 0xFFFF}


def reloc_masks(elf, section: str = ".text") -> dict:
    """offset -> the bits a relocation fills in, for one section of a
    relocatable object (a compiled source file)."""
    idx = next((i for i, s in enumerate(elf.iter_sections()) if s.name == section), None)
    masks = {}
    for s in elf.iter_sections():
        if s["sh_type"] in ("SHT_REL", "SHT_RELA") and s["sh_info"] == idx:
            for r in s.iter_relocations():
                masks[r["r_offset"]] = masks.get(r["r_offset"], 0) | RELOC_FIELDS.get(r["r_info_type"], 0xFFFFFFFF)
    return masks


def fields(code: bytes, masks: dict, start: int = 0):
    """code as words with only the fields our object relocates masked
    (masks from reloc_masks(), start = the function's offset in the section).
    Unlike normalise(), constants and offsets the linker does not touch must
    equal retail: a match compared this way differs from retail only in what
    the link fills in."""
    return tuple(w & ~masks.get(start + i * 4, 0) & 0xFFFFFFFF
                 for i, (w,) in enumerate(struct.iter_unpack("<I", code[: len(code) // 4 * 4])))


def sections(elf):
    return [(s["sh_addr"], s["sh_size"], s.name, s.data() if s["sh_type"] != "SHT_NOBITS" else b"")
            for s in elf.iter_sections() if s["sh_addr"]]


def read(secs, addr, size):
    for a, n, _, d in secs:
        if a <= addr and addr + size <= a + n and d:
            return d[addr - a: addr - a + size]
    return None

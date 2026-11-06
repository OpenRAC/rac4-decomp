"""Check the PAL packing draft's one-byte difference and bitwise equivalence.

Inputs are supplied locally; this script never executes either input.
Example after compiling the draft with tools/cc.sh and -O1:
    python research/ps2recomp-pal/verify_00470970.py baserom/pal/main.elf build/packing.o
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path

from elftools.elf.elffile import ELFFile

NAME, ADDRESS, SIZE = "func_00470970", 0x470970, 32
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("retail_elf", type=Path)
parser.add_argument("object_elf", type=Path)
parser.add_argument("--report", type=Path)
args = parser.parse_args()

with args.retail_elf.open("rb") as stream:
    elf = ELFFile(stream)
    assert elf["e_machine"] == "EM_MIPS" and elf.elfclass == 32 and elf.little_endian
    text = elf.get_section_by_name(".text")
    offset = ADDRESS - text["sh_addr"]
    assert 0 <= offset <= text["sh_size"] - SIZE
    retail = text.data()[offset:offset + SIZE]

with args.object_elf.open("rb") as stream:
    elf = ELFFile(stream)
    assert elf["e_machine"] == "EM_MIPS" and elf.elfclass == 32 and elf.little_endian
    symbols = [s for s in elf.get_section_by_name(".symtab").iter_symbols()
               if s.name == NAME and s["st_info"]["type"] == "STT_FUNC"]
    assert len(symbols) == 1
    symbol = symbols[0]
    section = elf.get_section(symbol["st_shndx"])
    start = symbol["st_value"] - section["sh_addr"]
    assert symbol["st_size"] == SIZE and 0 <= start <= section["sh_size"] - SIZE
    code = section.data()[start:start + SIZE]
    for relocations in elf.iter_sections():
        if relocations["sh_type"] in ("SHT_REL", "SHT_RELA"):
            if relocations["sh_info"] == symbol["st_shndx"]:
                assert not any(start <= r["r_offset"] < start + SIZE
                               for r in relocations.iter_relocations())


def execute(data):
    # An output bit is represented exactly as the disjunction of its input
    # bits. There are no arithmetic operations or negations in this subset.
    registers = [tuple(0 for _ in range(64))]
    registers += [tuple(1 << (r * 64 + b) for b in range(64))
                  for r in range(1, 32)]
    stores, returns = [], []
    for offset in range(0, len(data), 4):
        word = struct.unpack_from("<I", data, offset)[0]
        op = word >> 26
        rs, rt, rd = (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31
        shamt, funct = (word >> 6) & 31, word & 63
        if op == 0 and funct in (0x38, 0x3C):
            assert rs == 0 and rd != 0
            amount = shamt + (32 if funct == 0x3C else 0)
            registers[rd] = (0,) * amount + registers[rt][:64 - amount]
        elif op == 0 and funct == 0x25:
            assert shamt == 0 and rd != 0
            registers[rd] = tuple(a | b for a, b in zip(registers[rs], registers[rt]))
        elif op == 0 and funct == 8:
            assert rs == 31 and rt == rd == shamt == 0 and offset == SIZE - 8
            returns.append(registers[rs])
        elif op == 0x3F:
            assert offset == SIZE - 4
            immediate = (word & 0x7FFF) - (word & 0x8000)
            stores.append((registers[rs], immediate, registers[rt]))
        else:
            raise AssertionError("Instruction outside the admitted shift/OR/return/store subset")
    assert len(stores) == len(returns) == 1
    return registers, stores, returns


different = [i for i, (a, b) in enumerate(zip(code, retail)) if a != b]
assert different == [14]
ours = struct.unpack_from("<I", code, 12)[0]
original = struct.unpack_from("<I", retail, 12)[0]
assert ours & 0xFC00FFFF == original & 0xFC00FFFF
assert ((ours >> 21) & 31) == ((original >> 16) & 31)
assert ((ours >> 16) & 31) == ((original >> 21) & 31)
assert execute(code) == execute(retail)

# Negative controls check both the symbolic comparison and subset rejection.
wrong = bytearray(code)
struct.pack_into("<I", wrong, 4, struct.unpack_from("<I", wrong, 4)[0] ^ (1 << 6))
assert execute(wrong) != execute(retail)
wrong = bytearray(code)
struct.pack_into("<I", wrong, 12, ours ^ 1)
try:
    execute(wrong)
except AssertionError:
    pass
else:
    raise AssertionError("Unsupported AND was not rejected")

source = Path(__file__).parent / "drafts" / (NAME + ".c")
evidence = {
    "name": NAME,
    "version": "SCES_532.85",
    "program": "main",
    "address": f"{ADDRESS:08X}",
    "size": SIZE,
    "source_sha256": hashlib.sha256(source.read_bytes()).hexdigest(),
    "retail_elf_sha256": hashlib.sha256(args.retail_elf.read_bytes()).hexdigest(),
    "object_elf_sha256": hashlib.sha256(args.object_elf.read_bytes()).hexdigest(),
    "differing_bytes": len(different),
    "differing_words": 1,
    "difference": "OR source operands exchanged at function offset 0xC",
    "symbolic_result": "Identical lower 64 bits of all GPRs, ordered store and return target for every input bit pattern",
    "method": "Exact bit-origin disjunctions for logical shift and OR; no sampling",
    "negative_controls": "Changed shift breaks equivalence; unsupported AND rejected",
    "relocations": 0,
    "limitations": ["Not a byte-exact match", "Original C prototype unconfirmed",
                    "Not a whole-game runtime test", "Upper 64 bits of 128-bit GPRs not modeled"],
}
report = json.dumps(evidence, indent=2) + "\n"
if args.report:
    args.report.write_text(report, encoding="utf-8", newline="\n")
print(report, end="")

"""Small synthetic ELF32/MIPS objects for reader and assembler regression tests.

All contents are supplied by the tests. No compiler, game image or retained
object is needed. Supplied sections and symbols use indices starting at one;
the null ELF section and symbol are added automatically.
"""
from dataclasses import dataclass
import struct


@dataclass(frozen=True)
class ElfSection:
    name: str
    data: bytes
    flags: int = 0x6
    section_type: int = 1
    address: int = 0


@dataclass(frozen=True)
class ElfSymbol:
    name: str
    section_index: int
    value: int
    size: int
    symbol_type: int = 2


def elf_bytes(sections, symbols, relocations=(), elf_type=1):
    """Build a little-endian ELF32/MIPS object with a symbol table.

    ``relocations`` contains ``(owner_section_index, records)`` pairs, where
    each record is ``(offset, relocation_type, symbol_index)``. Records use
    ordinary ``SHT_REL`` MIPS relocations; symbol index zero is valid.
    """
    supplied = list(sections)
    symbols = list(symbols)
    relocation_groups = list(relocations)
    strtab_index = 1 + len(supplied) + len(relocation_groups)
    symtab_index = strtab_index + 1
    shstrtab_index = symtab_index + 1

    string_data = bytearray(b"\0")
    symbol_data = bytearray(16)
    for symbol in symbols:
        name_offset = len(string_data) if symbol.name else 0
        if symbol.name:
            string_data.extend(symbol.name.encode("ascii") + b"\0")
        symbol_data.extend(struct.pack(
            "<IIIBBH", name_offset, symbol.value, symbol.size,
            0x10 | symbol.symbol_type, 0, symbol.section_index,
        ))

    entries = [dict(name=s.name, data=s.data, kind=s.section_type, flags=s.flags,
                    address=s.address, link=0, info=0, alignment=4, entry_size=0)
               for s in supplied]
    for number, (owner, records) in enumerate(relocation_groups):
        if not 1 <= owner <= len(supplied):
            raise ValueError("relocation owner is not a supplied section")
        payload = b"".join(struct.pack("<II", offset, (symbol << 8) | kind)
                           for offset, kind, symbol in records)
        entries.append(dict(name=f".rel{supplied[owner - 1].name}.{number}",
                            data=payload, kind=9, flags=0, address=0,
                            link=symtab_index, info=owner, alignment=4, entry_size=8))
    entries.extend([
        dict(name=".strtab", data=bytes(string_data), kind=3, flags=0,
             address=0, link=0, info=0, alignment=1, entry_size=0),
        dict(name=".symtab", data=bytes(symbol_data), kind=2, flags=0,
             address=0, link=strtab_index, info=1, alignment=4, entry_size=16),
        dict(name=".shstrtab", data=b"", kind=3, flags=0,
             address=0, link=0, info=0, alignment=1, entry_size=0),
    ])

    names = bytearray(b"\0")
    for entry in entries:
        entry["name_offset"] = len(names)
        names.extend(entry["name"].encode("ascii") + b"\0")
    entries[-1]["data"] = bytes(names)

    image = bytearray(52)
    headers = [bytes(40)]
    for entry in entries:
        while len(image) % entry["alignment"]:
            image.append(0)
        offset = len(image)
        if entry["kind"] != 8:  # SHT_NOBITS has size, but no file payload.
            image.extend(entry["data"])
        headers.append(struct.pack(
            "<IIIIIIIIII", entry["name_offset"], entry["kind"], entry["flags"],
            entry["address"], offset, len(entry["data"]), entry["link"],
            entry["info"], entry["alignment"], entry["entry_size"],
        ))
    while len(image) % 4:
        image.append(0)
    section_offset = len(image)
    image.extend(b"".join(headers))
    identity = b"\x7fELF\x01\x01\x01" + bytes(9)
    image[:52] = struct.pack(
        "<16sHHIIIIIHHHHHH", identity, elf_type, 8, 1, 0, 0, section_offset,
        0, 52, 0, 0, 40, len(headers), shstrtab_index,
    )
    return bytes(image)

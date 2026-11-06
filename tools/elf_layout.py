"""Locate compiled functions by their ELF section ownership.

Function offsets are relative to their owning section. Distinct executable
sections can each contain a function at offset zero; neither code nor
relocations may be borrowed from another section with the same offset.
"""
from dataclasses import dataclass
from typing import Any


@dataclass(frozen=True)
class FunctionLayout:
    symbol: Any
    section_index: int
    section_name: str
    section_data: bytes
    start: int
    size: int

    @property
    def name(self) -> str:
        return self.symbol.name

    @property
    def end(self) -> int:
        return self.start + self.size

    @property
    def code(self) -> bytes:
        return self.section_data[self.start:self.end]


def section_index(elf, section: int | str) -> int | None:
    """Resolve a section identity; names must be unique when used."""
    if isinstance(section, int):
        if section < 0 or section >= elf.num_sections():
            raise ValueError("invalid ELF section index: %s" % section)
        return section
    indices = [i for i, candidate in enumerate(elf.iter_sections()) if candidate.name == section]
    if len(indices) > 1:
        raise ValueError("ambiguous ELF section name: %s" % section)
    return indices[0] if indices else None


def relocation_sections(elf, owner: int | str):
    """Yield relocation sections applying to exactly one owning section."""
    index = section_index(elf, owner)
    if index is None:
        return
    for section in elf.iter_sections():
        if section["sh_type"] in ("SHT_REL", "SHT_RELA") and section["sh_info"] == index:
            yield section


def _function_layout(elf, symbol, data_cache):
    if symbol["st_info"]["type"] != "STT_FUNC":
        return None
    index = symbol["st_shndx"]
    if not isinstance(index, int) or index == 0:
        return None
    section_index(elf, index)
    section = elf.get_section(index)
    if section["sh_type"] != "SHT_PROGBITS" or not section["sh_flags"] & 0x4:
        raise ValueError("function %s is not in an executable code section" % symbol.name)
    if index not in data_cache:
        data_cache[index] = section.data()
    data = data_cache[index]
    start = symbol["st_value"]
    elf_type = elf["e_type"]
    if elf_type in ("ET_EXEC", "ET_DYN"):
        start -= section["sh_addr"]
    elif elf_type != "ET_REL":
        raise ValueError("unsupported ELF function address model: %s" % elf_type)
    size = symbol["st_size"]
    if start < 0 or size < 0 or start + size > len(data):
        raise ValueError("function %s lies outside section %s" % (symbol.name, section.name))
    return FunctionLayout(symbol, index, section.name, data, start, size)


def function_layout(elf, symbol) -> FunctionLayout | None:
    """Read one defined STT_FUNC from its executable section, checking bounds."""
    return _function_layout(elf, symbol, {})


def functions(elf):
    """Yield all defined functions, sharing each owning section's byte read."""
    symbols = elf.get_section_by_name(".symtab")
    if symbols is None:
        return
    data_cache = {}
    for symbol in symbols.iter_symbols():
        function = _function_layout(elf, symbol, data_cache)
        if function is not None:
            yield function

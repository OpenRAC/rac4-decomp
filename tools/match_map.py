#!/usr/bin/env python3
"""match_map.py: where each function of src/ is on one disc, and whether its C matches there.

    python3 tools/match_map.py [--version us|pal] --write   # config/<version>/map.tsv from a build (needs the dumps)
    python3 tools/match_map.py [--version us|pal] --update-native SOURCE...  # checked native rows; retain the baseline
    python3 tools/match_map.py [--version us|pal] --check   # every src/ function and near miss has a row (CI)

The C in src/ is named by US addresses (func_XXXXXXXX, func_LNN_XXXXXXXX: the US executable's
and the US overlays' addresses, config/functions.tsv, config/overlay_functions.tsv) and checked
function by function by tools/audit_matches.py, which stays as it is. For each version's report
every source function is looked up in that disc's programs (tools/levels.py dump):

  - its compiled code (build/obj/, build/libgcc/, build/libm/: tools/build.sh,
    build_libgcc.sh, build_libm.sh, the file's own flags) is searched for in the section that
    holds its kind of code (core.text for core, libgcc and libm; net.text; the resident menu
    .text, then frontbin's; for a level function the level programs, its own level's first),
    comparing words with only the fields its object relocates masked (retail.fields(), as
    tools/audit_matches.py does: constants and offsets must be equal);
  - where it is found it is `match`, with the place(s) (program, section, address, size) and the
    catalogue name of the function there (config/<version>/inventory.tsv for the main image and
    frontbin, functions.tsv for the levels). Which find: on the US disc the one at the address
    its name gives first; then one where the inventory starts a function of its size, then
    where it starts one, then a single find inside one (the inventory then takes the C's start
    and end as proven). When identical code is in several places of one section, the one
    nearest the address the unique finds around it predict is kept;
  - a US catalogue name the old lists do not have (phase 2's C: src/core/, src/net/,
    src/game/ ADDR.c, src/frontbin/FB_ADDR.c, src/overlays/.../LNN_ADDR.c) is, on the US disc,
    compared at its catalogue place (`match` or `nomatch`); on PAL it is looked up by its code
    like the rest, in the section its US place says;
  - where it is not found it is `differs`: the C builds to the other version's bytes only (on
    PAL: a 50 Hz constant against 60 Hz, a field moved, the code changed). Its C stays in src/.
  - C in src/pal/ is written against PAL under its PAL catalogue name (tools/check_func.py
    --version pal): on PAL it is `match` when it builds to the bytes of that function, else
    `nomatch`; on the US disc it is `other` (not a US function);
  - a near miss (nonmatching/**/func_*.c) is `near`: the function whose code is the US function's
    (its US retail bytes, tools/retail.py normalise(), same size), with the near miss's closeness
    (its verdict, rac1-decomp's closeness()) as its fuzzy match; `none` when no function has it.

config/<version>/map.tsv (committed: names, addresses, sizes; no bytes): source name, source
file, status, catalogue names, places (program:section:address:size), closeness (percent; 100
for a match). tools/progress.py counts from it without the disc, and tools/inventory.py takes a
matched place's start and end as proven.
"""
import argparse
import bisect
import collections
import glob
import os
import re
import stat
import struct
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import elf_layout
NAME = re.compile(r"^func_(?:(L\d\d)_|FB_)?([0-9A-F]{8})$")
HEAD = """# Each function of src/ (and each near miss in nonmatching/) on the %s disc (tools/match_map.py --write):
# source name (US names; PAL names in src/pal/), source file, status (match: its C builds to this disc's bytes;
# differs: to the other version's only; nomatch: src/pal/ C that does not build to its PAL function; other:
# src/pal/ C on the US disc; near: a near miss of a function here; none: a near miss of no function here),
# catalogue names, places (program:section:address:size), closeness (percent).
"""


def read_map(path=None):
    """[{name, file, status, names: [catalogue names], places: [(program, section, address, size)], closeness}]"""
    import levels
    path = path or levels.cfg("map.tsv")
    out = []
    if not os.path.exists(path):
        return out
    with open(path, encoding="utf-8") as source:
        for line in source:
            if line.startswith("#") or not line.strip():
                continue
            n, f, st, pal, places, close = line.rstrip("\n").split("\t")
            pl = []
            for p in places.split(",") if places != "-" else []:
                prog, sec, a, sz = p.split(":")
                pl.append((prog, sec, int(a, 16), int(sz)))
            out.append({"name": n, "file": f, "status": st, "names": [] if pal == "-" else pal.split(","),
                        "places": pl, "closeness": float(close)})
    return out


# --- what src/ and nonmatching/ define (no build needed) -------------------------------

def source_functions():
    """{US name: source file} of src/ (as tools/gen_progress_report.py finds them), the libgcc
    and libm functions under their config/functions.tsv names."""
    import gen_progress_report as g
    out = {}
    for path, names in g.source_functions().items():
        src = path.split(":")[0]
        for n in names:
            out.setdefault(n, src)
    return out


def near_misses():
    """{US name: file} of nonmatching/."""
    return {os.path.basename(p)[:-2]: os.path.relpath(p, ROOT).replace(os.sep, "/")
            for p in sorted(glob.glob(os.path.join(ROOT, "nonmatching", "*", "func_*.c")))}


# --- the build ----------------------------------------------------------------------

def object_of(src):
    return os.path.join(ROOT, "build", "obj", src[len("src/"):].replace("/", "_")[:-2] + ".o")


def compiled(paths=None):
    """{US name: (code, {offset: mask})} of every compiled function (tools/audit_matches.py's
    names: libgcc and libm symbols through config/libgcc.tsv, config/libm.tsv)."""
    import retail
    from elftools.elf.elffile import ELFFile
    sizes = {}
    with open(os.path.join(ROOT, "config", "functions.tsv")) as source:
        for l in source:
            if l.strip() and not l.startswith("#"):
                n, a, s, _ = l.rstrip("\n").split("\t")
                sizes[int(a, 16)] = n
    alias = {}
    for tsv in ("libgcc.tsv", "libm.tsv"):
        p = os.path.join(ROOT, "config", tsv)
        if os.path.exists(p):
            with open(p) as source:
                for l in source:
                    if l.strip() and not l.startswith("#"):
                        obj, sym, a, _ = l.rstrip("\n").split("\t")
                        alias[(obj[:-2] if obj.endswith(".o") else obj, sym)] = sizes[int(a, 16)]
    out = {}
    if paths is None:
        paths = sorted(glob.glob(os.path.join(ROOT, "build", "obj", "*.o")) + glob.glob(os.path.join(ROOT, "build", "libgcc", "*.o"))
                       + glob.glob(os.path.join(ROOT, "build", "libm", "*.o")))
    for path in paths:
        with open(path, "rb") as source:
            elf = ELFFile(source)
            for function in elf_layout.functions(elf):
                s = function.symbol
                name = alias.get((os.path.splitext(os.path.basename(path))[0], s.name))
                if name is None:
                    if not NAME.match(s.name):
                        continue
                    name = s.name
                start, code = function.start, function.code
                masks = retail.reloc_masks(elf, function.section_index)
                m = {k - start: v for k, v in masks.items() if start <= k < start + len(code)}
                out[name] = (code, m)
    return out


# --- the PAL programs ---------------------------------------------------------------

class Disc:
    """The selected disc's code sections and the names of their functions."""

    def __init__(self):
        import inventory as inv
        import level_catalogue as lc
        import levels
        self.sections = {}       # (program, section) -> (base, bytes)
        for prog in ("main", "frontbin"):
            for name, (a, b) in levels.sections_of(levels.program_path(prog)).items():
                if name in ("core.text", "net.text", ".text") and not (prog == "frontbin" and name == "net.text"):
                    self.sections[(prog, name)] = (a, b)
        self.levels = inv.distinct_levels()
        for n in self.levels:
            a, b = levels.sections_of(levels.elf_path(n))[".text"]
            self.sections[("level_%02d" % n, ".text")] = (a, b)
        self.copy_of = {r["number"]: r["copy_of"] for r in levels.read_table()}
        self.names = {}          # (program, section, address) -> (name, size)
        pairs = {v: k for k, v in lc.read_pairs().items()}
        for prog, rows in inv.read_inventory().items():
            for sec, a, n, kind in rows:
                nm = ("func_FB_%08X" if prog == "frontbin" else "func_%08X") % a
                self.names[(prog, sec, a)] = (nm, n)
        for name, kind, size, fp, rem, places in lc.read_catalogue():
            for lv, a in places:
                self.names[("level_%02d" % lv, ".text", a)] = (name, size)
        self.pairs = pairs

    def find(self, key, code, masks):
        """Addresses in section KEY where CODE equals the bytes with MASKS' fields masked."""
        import retail
        base, data = self.sections[key]
        n = len(code)
        if n < 4:
            return []
        want = retail.fields(code, masks, 0)
        # an anchor: the longest run of unmasked words (at most 4)
        best, run = (0, 0), 0
        for i in range(n // 4):
            if masks.get(4 * i, 0):
                run = 0
            else:
                run += 1
                if run > best[0]:
                    best = (run, i - run + 1)
        out = []
        if best[0] == 0:
            cands = [a for (p, s, a) in self.names if (p, s) == key]
            for a in cands:
                o = a - base
                if retail.fields(data[o:o + n], masks, 0) == want:
                    out.append(a)
            return out
        k = min(best[0], 4)
        first = best[1]
        needle = code[4 * first:4 * first + 4 * k]
        i = data.find(needle)
        while i >= 0:
            o = i - 4 * first
            if i % 4 == 0 and o >= 0 and o + n <= len(data) and retail.fields(data[o:o + n], masks, 0) == want:
                out.append(base + o)
            i = data.find(needle, i + 1)
        return out


def search_order(name, us_seg, disc):
    """[(program, section)] to look in for a US function, best first, in groups: the first
    group with a find wins."""
    m = NAME.match(name)
    if us_seg == "frontbin":
        return [[("frontbin", ".text")], [("main", ".text")],
                [("level_%02d" % n, ".text") for n in disc.levels]]
    if us_seg == "overlay" and not (m and m.group(1)):
        return [[("level_%02d" % n, ".text") for n in disc.levels], [("main", ".text")]]
    if us_seg in ("core_text", "libgcc", "libm"):
        return [[("main", "core.text")]]
    if us_seg == "net_text":
        return [[("main", "net.text")]]
    if us_seg == "text":
        return [[("main", ".text")], [("frontbin", ".text")],
                [("level_%02d" % n, ".text") for n in disc.levels]]
    lv = int(m.group(1)[1:])
    own = disc.copy_of.get(lv, lv)
    return [[("level_%02d" % own, ".text")], [("level_%02d" % n, ".text") for n in disc.levels if n != own],
            [("main", ".text")]]


SEGMENT_OF = {("main", "core.text"): "core_text", ("main", "net.text"): "net_text",
              ("main", ".text"): "text", ("frontbin", ".text"): "frontbin"}


def us_info():
    """{US name: (segment, address)}: the old US lists' (config/functions.tsv,
    config/overlay_functions.tsv), then every US catalogue name they do not have (new_us_names())."""
    import gen_progress_report as g
    out = {}
    for n, f in g.load_functions().items():
        seg = f["seg"]
        out[n] = ("overlay" if seg.startswith("ovl_") else seg, f["addr"])
    for n, (prog, sec, a, size, kind) in us_catalogue().items():
        if n not in out:
            out[n] = (SEGMENT_OF.get((prog, sec), "overlay"), a)
    return out


_US = {}


def us_catalogue():
    """{name: (program, section, address, size, kind)} of the US disc's catalogue
    (tools/check_func.py places(), config/us/), whatever version is selected."""
    if "places" not in _US:
        import check_func
        import levels
        was = levels.V
        levels.select("us")
        try:
            _US["places"] = check_func.places()
        finally:
            levels.select(was)
    return _US["places"]


def us_bytes(name):
    """The US disc's bytes of a US catalogue function (its dump, baserom/us/), or None."""
    import check_func
    import levels
    p = us_catalogue().get(name)
    if p is None:
        return None
    was = levels.V
    levels.select("us")
    try:
        return check_func.disc_bytes(p[:4])
    finally:
        levels.select(was)


def new_us_names():
    """The US catalogue names the old US lists do not have: functions phase 2 decompiles
    under their catalogue name (src/core/, src/net/, src/game/ ADDR.c, src/frontbin/FB_ADDR.c,
    src/overlays/.../LNN_ADDR.c). On the US disc they are compared at their catalogue place."""
    import gen_progress_report as g
    old = set(g.load_functions())
    return {n for n in us_catalogue() if n not in old}


def resolve(hits_by_name, info):
    """Keep one place per section for each function: the nearest to the address the unique
    finds around it predict (US address plus their US->PAL offset)."""
    unique = collections.defaultdict(list)
    for name, (key, hits) in hits_by_name.items():
        if len(hits) == 1:
            unique[key].append((info[name][1], hits[0]))
    for k in unique:
        unique[k].sort()
    out = {}
    for name, (key, hits) in hits_by_name.items():
        if len(hits) <= 1:
            out[name] = (key, hits)
            continue
        us = info[name][1]
        u = unique.get(key, [])
        if u:
            i = bisect.bisect_left(u, (us, -1))
            near = [u[j] for j in (i - 1, i) if 0 <= j < len(u)]
            ua, pa = min(near, key=lambda x: abs(x[0] - us))
            pred = us + (pa - ua)
        else:
            pred = us
        out[name] = (key, [min(hits, key=lambda h: abs(h - pred))])
    return out


def near_places(near, info, disc):
    """{US name: (key, address, closeness)} for the near misses whose US function's code is a PAL
    function's (retail.normalise() equal, same size)."""
    import layout
    import retail
    idx = collections.defaultdict(list)
    for (prog, sec, a), (nm, size) in disc.names.items():
        if (prog, sec) not in disc.sections:
            continue
        base, data = disc.sections[(prog, sec)]
        idx[(retail.normalise(data[a - base:a - base + size]), size)].append(((prog, sec), a))
    out = {}
    for name, path in near.items():
        try:
            b = layout.retail_bytes(name)
        except SystemExit:
            b = us_bytes(name)               # a US catalogue name the old lists do not have
        if b is None:
            out[name] = None              # no US function of that name: nothing to carry over
            continue
        size = len(b)
        while size >= 4 and b[size - 4:size] == bytes(4) and not (size >= 8 and _jump(b[size - 8:size - 4])):
            size -= 4
        b = b[:size]
        cands = idx.get((retail.normalise(b), len(b)), [])
        if not cands:
            out[name] = None
            continue
        seg = info.get(name, ("overlay", 0))[0]
        order = [k for grp in search_order(name, seg, disc) for k in grp]
        cands.sort(key=lambda c: (order.index(c[0]) if c[0] in order else 99, abs(c[1] - info.get(name, ("", 0))[1])))
        out[name] = (cands[0][0], cands[0][1], closeness(os.path.join(ROOT, path)))
    return out


def _jump(w):
    x = struct.unpack("<I", w)[0]
    return (x & 0xFC1FFFFF) == 8 or x >> 26 == 2 or x >> 16 == 0x1000


def closeness(path):
    """rac1-decomp's closeness of a near miss: the share of bytes that match, from its verdict."""
    first = open(path, errors="replace").readline()
    m = re.search(r"BYTES (\d+)/(\d+)", first)
    return round(100.0 * (1 - int(m.group(1)) / int(m.group(2))), 2) if m else 0.0


def native_row(name, source, built, table):
    """Compare C named by this disc's catalogue, or inventory PAL C on US."""
    import levels
    if source.startswith("src/pal/") and levels.V == "us":
        return (name, source, "other", "-", "-", 0.0)
    import check_func
    import retail
    place = table.get(name)
    if name not in built or place is None:
        return (name, source, "nomatch", "-", "-", 0.0)
    code, masks = built[name]
    want = check_func.disc_bytes(place[:4])
    ok = (len(code) == len(want) == place[3]
          and retail.fields(code, masks, 0) == retail.fields(want, masks, 0))
    return (name, source, "match" if ok else "nomatch", name,
            "%s:%s:%08X:%d" % place[:4], 100.0 if ok else 0.0)


def serialize_row(row):
    """The shared on-disk representation of a generated map row."""
    return ("%s\t%s\t%s\t%s\t%s\t%.2f\n" % row).encode("utf-8")


def write_payload(path, payload, expected=None):
    """Replace one complete map after validation; never publish a partial write."""
    directory = os.path.dirname(os.path.abspath(path))
    mode = stat.S_IMODE(os.stat(path).st_mode) if os.path.exists(path) else None
    fd, temporary = tempfile.mkstemp(prefix=os.path.basename(path) + ".", suffix=".tmp", dir=directory)
    try:
        with os.fdopen(fd, "wb") as destination:
            destination.write(payload)
        if mode is not None:
            os.chmod(temporary, mode)
        if expected is not None:
            with open(path, "rb") as source:
                if source.read() != expected:
                    raise ValueError("baseline map changed during validation: %s" % path)
        os.replace(temporary, path)
    finally:
        if os.path.exists(temporary):
            os.unlink(temporary)


def write():
    import levels
    pal = Disc()
    info = us_info()
    src = source_functions()
    built = compiled()
    new = new_us_names()
    hits = {}
    for name, f in src.items():
        if name not in built or f.startswith("src/pal/") or (levels.V == "us" and name in new):
            continue
        code, masks = built[name]
        seg, us_addr = info.get(name, ("overlay", 0))
        own = [lambda k, a: a == us_addr] if levels.V == "us" else []
        for grp in search_order(name, seg, pal):
            found = [(k, a) for k in grp for a in pal.find(k, code, masks)]
            # (on the US disc where its name says,) where the inventory starts a function of
            # that size, else where it starts one, else (the cut is wrong) a single find inside one
            for rule in own + [lambda k, a: pal.names.get((k[0], k[1], a), (0, -1))[1] == len(code),
                               lambda k, a: (k[0], k[1], a) in pal.names]:
                best = [h for h in found if rule(*h)]
                if best:
                    found = best
                    break
            else:
                found = found if len(found) == 1 else []
            if found:
                # one section: the first that has it (the level's own program first)
                k0 = found[0][0]
                hits[name] = (k0, [a for k, a in found if k == k0])
                break
    hits = resolve(hits, info)
    # the menu .text's matches in frontbin's copy of it too (its second link): the inventory
    # takes their extents there as well, so the pairs stay pairs
    fb_hits, fb_info = {}, {}
    for name, (key, addrs) in hits.items():
        if key == ("main", ".text") and addrs:
            code, masks = built[name]
            found = pal.find(("frontbin", ".text"), code, masks)
            if found:
                fb_hits[name] = (("frontbin", ".text"), found)
                fb_info[name] = ("text", addrs[0])
    fb_hits = resolve(fb_hits, fb_info)
    rows = []
    import check_func
    table = check_func.places()
    for name, f in sorted(src.items()):
        if f.startswith("src/pal/") or (levels.V == "us" and name in new):
            rows.append(native_row(name, f, built, table))
            continue
        if name not in built:
            rows.append((name, f, "differs", "-", "-", 0.0))
            continue
        code = built[name][0]
        if name not in hits:
            rows.append((name, f, "differs", "-", "-", 0.0))
            continue
        key, addrs = hits[name]
        a = addrs[0]
        nm = pal.names.get((key[0], key[1], a), (None, None))[0]
        if nm and pal.names[(key[0], key[1], a)][1] != len(code):
            nm = None                      # not where the inventory cuts: a proven extent
        if nm is None:
            nm = ("func_L%s_%08X" % (key[0][6:], a) if key[0].startswith("level_")
                  else ("func_FB_%08X" if key[0] == "frontbin" else "func_%08X") % a)
        places = "%s:%s:%08X:%d" % (key[0], key[1], a, len(code))
        if name in fb_hits and fb_hits[name][1]:
            fa = fb_hits[name][1][0]
            places += ",frontbin:.text:%08X:%d" % (fa, len(code))
        rows.append((name, f, "match", nm, places, 100.0))
    near = near_misses()
    for name, v in sorted(near_places(near, info, pal).items()):
        if name in src:
            continue
        if v is None:
            rows.append((name, near[name], "none", "-", "-", 0.0))
        else:
            (prog, sec), a, c = v
            nm, size = pal.names[(prog, sec, a)]
            rows.append((name, near[name], "near", nm, "%s:%s:%08X:%d" % (prog, sec, a, size), c))
    write_payload(levels.cfg("map.tsv"), (HEAD % levels.version_id()).encode("utf-8")
                  + b"".join(serialize_row(row) for row in rows))
    c = collections.Counter(r[2] for r in rows)
    print("wrote %s: %s" % (os.path.relpath(levels.cfg("map.tsv"), ROOT), ", ".join(
        "%d %s" % (c[k], k) for k in ("match", "differs", "nomatch", "other", "near", "none") if c[k])))


def update_native(paths):
    """Update selected native sources only, keeping every unrelated baseline byte."""
    import check_func
    import gen_progress_report as g
    import levels

    root = os.path.realpath(ROOT)
    src_root = os.path.realpath(os.path.join(root, "src"))
    selected = set()
    for path in paths:
        absolute = os.path.realpath(path)
        if (os.path.commonpath((src_root, absolute)) != src_root
                or not absolute.endswith(".c") or not os.path.isfile(absolute)):
            raise ValueError("expected an existing C source under src/: %s" % path)
        relative = os.path.relpath(absolute, root).replace(os.sep, "/")
        if relative in selected:
            raise ValueError("duplicate selected source: %s" % relative)
        selected.add(relative)
    if not selected:
        raise ValueError("no native sources selected")
    if levels.V == "pal" and any(not path.startswith("src/pal/") for path in selected):
        raise ValueError("US sources on PAL require the full --write search")

    definitions = g.source_functions()
    owners = collections.defaultdict(list)
    for path, names in definitions.items():
        for name in names:
            owners[name].append(path.split(":")[0])
    chosen = {}
    for path in sorted(selected):
        names = definitions.get(path, [])
        if not names:
            raise ValueError("no canonical function definitions in %s" % path)
        for name in names:
            if not NAME.fullmatch(name) or owners[name] != [path] or name in chosen:
                raise ValueError("duplicate, colliding or noncanonical function: %s" % name)
            chosen[name] = path

    map_path = levels.cfg("map.tsv")
    with open(map_path, "rb") as source:
        baseline = source.read()
    rows = read_map(map_path)
    if len({row["name"] for row in rows}) != len(rows):
        raise ValueError("baseline map contains duplicate function names")
    for row in rows:
        if row["file"] in selected and row["name"] not in chosen:
            raise ValueError("removed or moved existing definition: %s" % row["name"])
        if row["name"] in chosen and row["file"] != chosen[row["name"]]:
            raise ValueError("existing definition belongs to another source: %s" % row["name"])

    version = levels.V
    tables = {}
    try:
        for native_version in sorted({"pal" if path.startswith("src/pal/") else "us" for path in selected}):
            levels.select(native_version)
            tables[native_version] = check_func.places()
    finally:
        levels.select(version)
    replacements = {}
    for path in sorted(selected):
        native_version = "pal" if path.startswith("src/pal/") else "us"
        names = [name for name, source in chosen.items() if source == path]
        table = tables[native_version]
        for name in names:
            if name not in table:
                raise ValueError("not a native %s catalogue function: %s" % (native_version, name))
        built = {}
        if native_version == version:
            obj = object_of(path)
            if not os.path.isfile(obj):
                raise ValueError("missing compiled object for %s: %s" % (path, obj))
            built = compiled([obj])
        for name in names:
            row = native_row(name, path, built, table)
            if row[2] not in ("match", "other"):
                raise ValueError("native bytes or object definition differ: %s" % name)
            replacements[name] = serialize_row(row)

    output = []
    for line in baseline.splitlines(keepends=True):
        if line.startswith(b"#") or not line.strip():
            output.append(line)
            continue
        name = line.split(b"\t", 1)[0].decode("utf-8")
        output.append(replacements.pop(name) if name in replacements else line)
    if replacements and baseline and not baseline.endswith((b"\n", b"\r")):
        raise ValueError("baseline map must end with a newline before appending rows")
    output.extend(replacements[name] for name in sorted(replacements))
    write_payload(map_path, b"".join(output), expected=baseline)
    print("updated %d native functions in %s (baseline retained)" %
          (len(chosen), os.path.relpath(map_path, ROOT)))


def check():
    import levels
    rows = {r["name"]: r for r in read_map()}
    src, near = source_functions(), near_misses()
    problems = []
    for n, f in src.items():
        r = rows.get(n)
        if r is None or r["status"] not in ("match", "differs", "nomatch", "other") or r["file"] != f:
            problems.append("%s (%s) has no up-to-date row" % (n, f))
    for n, f in near.items():
        r = rows.get(n)
        if (r is None or r["status"] not in ("near", "none") or r["file"] != f) and n not in src:
            problems.append("near miss %s (%s) has no up-to-date row" % (n, f))
    for n, r in rows.items():
        if r["status"] in ("match", "differs", "nomatch", "other") and n not in src:
            problems.append("%s: a row but no C in src/" % n)
        if r["status"] in ("near", "none") and n not in near:
            problems.append("%s: a near-miss row but no file in nonmatching/" % n)
    for p in problems[:20]:
        print("error:", p)
    if problems:
        print("%d problems: rebuild (tools/build.sh, build_libgcc.sh, build_libm.sh) and run "
              "python3 tools/match_map.py --version %s --write" % (len(problems), levels.V))
        return 1
    print("%s OK (%d rows)" % (os.path.relpath(levels.cfg("map.tsv"), ROOT), len(rows)))
    return 0


def main():
    import levels
    levels.cli_version()
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    mode = ap.add_mutually_exclusive_group()
    mode.add_argument("--write", action="store_true")
    mode.add_argument("--update-native", nargs="+", metavar="SOURCE",
                      help="check selected native C sources and retain unrelated map rows")
    ap.add_argument("--check", action="store_true")
    a = ap.parse_args()
    if a.write:
        write()
    elif a.update_native:
        try:
            update_native(a.update_native)
        except ValueError as error:
            ap.error(str(error))
    if a.check or not (a.write or a.update_native):
        sys.exit(check())


if __name__ == "__main__":
    main()

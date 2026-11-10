#!/usr/bin/env python3
"""progress.py: how much of each version is matched C; its objdiff report (ByteMatch shows it; the README has only its badges).

    python3 tools/progress.py [--version us|pal]            # print the counts
    python3 tools/progress.py [--version us|pal] --write    # rewrite the report
    python3 tools/progress.py [--version us|pal] --check    # it is current (CI)

The US report (SCUS_974.65, the primary target and ByteMatch's default version) is
progress/report.json; the PAL one (SCES_532.85) progress/pal/report.json.

Adapted from rac3-uya-decomp-pal's tools/progress.py (b20190e; rac1-decomp's units and
categories). It needs no game data or toolchain: everything comes from src/, nonmatching/ and
the version's committed tables made from the binaries (config/<version>/):

  inventory.tsv        every function of the main image and frontbin (tools/inventory.py)
  frontend_pairs.tsv   frontbin's functions that are the main image's (tools/level_catalogue.py)
  functions.tsv        every distinct level function and its places (tools/level_catalogue.py)
  map.tsv              each src/ function's place and whether its C matches there, and each
                       near miss's function and closeness (tools/match_map.py)

Counted once, as rac1-decomp, rac2-decomp and rac3-uya-decomp-pal count them:
  - the main image's functions (core.text, net.text, the resident menu .text) and frontbin's own
    are the inventory's; frontbin's .text is the menu .text linked a second time, so a pair of
    frontend_pairs.tsv is one function, counted with the main image;
  - a level function counts once however many levels have it (the 33 levels that are byte-
    identical copies of another are that level): one with the menu .text's code is the main
    image's function; the others are in "Shared level code" (two or more distinct level
    programs) or in their level's unit;
  - a function is matched (exact) when C in src/ builds to its bytes (map.tsv, `match`); its
    fuzzy match is 100 then, otherwise the closeness of its near miss in nonmatching/ (`near`),
    otherwise 0. Exact and fuzzy are computed apart.

Units: one per source file of src/ that matches core code (the main image and frontbin); the
core functions no C matches yet in units of 64 KB of their section ("main/core.text/0011xxxx");
one "Shared level code" unit (category common) and one unit per level program with its own
functions ("Level 01: Dreadzone Station", categories levels and level_01). Categories: core
(everything in the main image and frontbin), core_text, libgcc, libm, net_text, menu_text,
frontbin; level_code, common, levels and level_NN. The same for both versions.
.github/workflows/progress.yml checks both and uploads them as SCUS_974.65_report and
SCES_532.85_report.
"""
import argparse
import collections
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import levels  # noqa: E402



def report_path():
    """progress/report.json for the US disc (ByteMatch's default), progress/<version>/ else."""
    if levels.V == "us":
        return os.path.join(ROOT, "progress", "report.json")
    return os.path.join(ROOT, "progress", levels.V, "report.json")


US_LIBGCC = (0x12EE30, 0x131A00)
BLOCK = 0x10000
SECTION_CATS = {("main", "core.text"): "core_text", ("main", "net.text"): "net_text",
                ("main", ".text"): "menu_text", ("frontbin", ".text"): "frontbin"}
CAT_NAMES = [("core", "Main program"), ("core_text", "Engine core (core.text)"), ("libgcc", "libgcc"),
             ("libm", "libm"), ("net_text", "Network (net.text)"), ("menu_text", "Resident menus (.text)"),
             ("frontbin", "frontbin's own code")]


def measures(fns):
    """objdiff's code measures for a list of functions ({"size", "done", "fuzzy"})."""
    total = sum(f["size"] for f in fns)
    done = sum(f["size"] for f in fns if f["done"])
    fuzzy = sum(f["size"] * f["fuzzy"] / 100.0 for f in fns)
    n, nd = len(fns), sum(1 for f in fns if f["done"])
    pct = lambda a, b: round(100.0 * a / b, 6) if b else 100.0
    return {"fuzzy_match_percent": pct(fuzzy, total), "total_code": str(total), "matched_code": str(done),
            "matched_code_percent": pct(done, total), "total_functions": n, "matched_functions": nd,
            "matched_functions_percent": pct(nd, n)}


def summed(units):
    m = measures([f for u in units for f in u["_fns"]])
    complete = sum(int(u["measures"]["total_code"]) for u in units if u["metadata"]["complete"])
    total = int(m["total_code"])
    m.update({"complete_code": str(complete),
              "complete_code_percent": round(100.0 * complete / total, 6) if total else 100.0,
              "total_units": len(units), "complete_units": sum(1 for u in units if u["metadata"]["complete"])})
    return m


def make_unit(name, fns, source, cats):
    fns = sorted(fns, key=lambda f: f["addr"])
    m = measures(fns)
    complete = bool(fns) and all(f["done"] for f in fns)
    m.update({"complete_code": m["total_code"] if complete else "0",
              "complete_code_percent": 100.0 if complete else 0.0, "total_units": 1, "complete_units": int(complete)})
    base = fns[0]["addr"]
    return {"name": name, "measures": m,
            "functions": [{"name": f["name"], "size": str(f["size"]), "fuzzy_match_percent": f["fuzzy"],
                           "address": str(f["addr"] - base),
                           "metadata": {"virtual_address": str(f["addr"])}} for f in fns],
            "metadata": {"complete": complete, "source_path": source, "progress_categories": cats},
            "_fns": fns}


def state():
    """The PAL functions (core and level) with their state, from the committed tables."""
    import inventory
    import level_catalogue as lc
    import match_map
    inv = inventory.read_inventory()
    cat = lc.read_catalogue()
    pairs = lc.read_pairs()                        # frontbin name -> main name
    rows = match_map.read_map()
    # the PAL function at each place: (program, section, address) -> name
    at = {}
    for prog, rs in inv.items():
        for sec, a, n, kind in rs:
            at[(prog, sec, a)] = ("func_FB_%08X" if prog == "frontbin" else "func_%08X") % a
    for name, kind, size, fp, rem, places in cat:
        for lv, a in places:
            at[("level_%02d" % lv, ".text", a)] = name
    canon = dict(pairs)                            # a frontbin function paired: the main one
    for name, kind, size, fp, rem, places in cat:
        if kind in ("main", "frontbin"):
            for lv, a in places:
                canon[at[("level_%02d" % lv, ".text", a)]] = name
    done, fuzzy, files = set(), collections.defaultdict(float), {}
    pal_of_us = {}
    for r in rows:
        for prog, sec, a, n in r["places"]:
            name = canon.get(at.get((prog, sec, a)), at.get((prog, sec, a)))
            if name is None:
                continue
            if r["status"] == "match":
                done.add(name)
                files.setdefault(name, r["file"])
                pal_of_us[r["name"]] = name
            elif r["status"] == "near":
                fuzzy[name] = max(fuzzy[name], r["closeness"])
    # libgcc and libm on PAL: the places of the US functions there
    libm_us = set()
    p = os.path.join(ROOT, "config", "libm.tsv")
    for l in open(p):
        if l.strip() and not l.startswith("#"):
            libm_us.add(int(l.split("\t")[2], 16))
    lib = {}
    for us, pal in pal_of_us.items():
        a = int(us[-8:], 16)
        if us.startswith("func_") and len(us) == 13:
            if US_LIBGCC[0] <= a < US_LIBGCC[1]:
                lib[pal] = "libgcc"
            elif a in libm_us:
                lib[pal] = "libm"
    gcc = [int(n[-8:], 16) for n, k in lib.items() if k == "libgcc"]
    gcc_range = (min(gcc), max(gcc) + 1) if gcc else (0, 0)

    def fn(name, addr, size):
        d = name in done
        return {"name": name, "addr": addr, "size": size, "done": d, "fuzzy": 100.0 if d else fuzzy.get(name, 0.0)}
    core = []
    for prog, rs in inv.items():
        for sec, a, n, kind in rs:
            name = at[(prog, sec, a)]
            if name in pairs:
                continue                           # counted as the main image's function
            c = SECTION_CATS[(prog, sec)]
            if c == "core_text" and (gcc_range[0] <= a < gcc_range[1] or lib.get(name) == "libgcc"):
                c = "libgcc"
            elif lib.get(name) == "libm":
                c = "libm"
            f = fn(name, a, n)
            f.update({"program": prog, "section": sec, "cat": c})
            core.append(f)
    shared, own = [], collections.defaultdict(list)
    for name, kind, size, fp, rem, places in cat:
        if kind not in ("shared", "level"):
            continue
        f = fn(name, places[0][1], size)
        (shared if kind == "shared" else own[places[0][0]]).append(f)
    return core, files, shared, own


def level_title(n):
    rows = levels.read_table()
    copies = [r["number"] for r in rows if r["copy_of"] == n and r["number"] != n]
    t = levels.title(n)
    if n == 41:
        return t + " (all %d multiplayer maps)" % (len(copies) + 1)
    if copies:
        return t + " (and %s)" % ", ".join("%02d" % c for c in copies)
    return t


def report():
    core, files, shared, own = state()
    units = []
    by_file = collections.defaultdict(list)
    rest = collections.defaultdict(list)
    for f in core:
        src = files.get(f["name"])
        if src:
            by_file[src].append(f)
        else:
            rest[(f["program"], f["section"], f["addr"] // BLOCK * BLOCK)].append(f)
    for src, fns in sorted(by_file.items()):
        name = os.path.splitext(src[len("src/"):])[0]
        units.append(make_unit(name, fns, src, ["core"] + sorted({f["cat"] for f in fns})))
    for (prog, sec, blk), fns in sorted(rest.items()):
        cats = ["core"] + sorted({f["cat"] for f in fns})
        units.append(make_unit("%s/%s/%04Xxxxx" % (prog, sec, blk >> 16), fns, "asm/%s/%s/%s" % (levels.V, prog, sec.lstrip(".").replace(".", "_")), cats))
    core_units = list(units)
    level_units = [make_unit("Shared level code", shared, "asm/%s (shared level code)" % levels.V, ["level_code", "common"])]
    for n in sorted(own):
        level_units.append(make_unit(level_title(n), own[n], "asm/%s/level_%02d/text" % (levels.V, n),
                                     ["level_code", "levels", "level_%02d" % n]))
    units += level_units
    cats = [{"id": "core", "name": "Main program", "measures": summed(core_units)}]
    for cid, cname in CAT_NAMES[1:]:
        # by each function's own section (a source file's unit can hold functions of two)
        us = [u for u in core_units if any(f["cat"] == cid for f in u["_fns"])]
        if us:
            fns = [f for u in us for f in u["_fns"] if f["cat"] == cid]
            m = measures(fns)
            m.update({"complete_code": "0", "complete_code_percent": 0.0, "total_units": len(us),
                      "complete_units": sum(1 for u in us if u["metadata"]["complete"])})
            cats.append({"id": cid, "name": cname, "measures": m})
    has = lambda c: [x for x in level_units if c in x["metadata"]["progress_categories"]]
    cats.append({"id": "level_code", "name": "Level code", "measures": summed(level_units)})
    cats.append({"id": "common", "name": "Shared level code", "measures": summed(has("common"))})
    cats.append({"id": "levels", "name": "Level-specific code", "measures": summed(has("levels"))})
    for x in has("levels"):
        cid = next(c for c in x["metadata"]["progress_categories"] if c.startswith("level_") and c != "level_code")
        cats.append({"id": cid, "name": x["name"], "measures": summed([x])})
    top = summed(units)
    for u in units:
        u.pop("_fns", None)
    return {"version": 2, "measures": top, "categories": cats, "units": units}


def text_of(rep):
    cat = {c["id"]: c for c in rep["categories"]}
    line = lambda label, x: "| %s | %s of %s | %s of %s bytes (%.2f%%) | %.2f%% |" % (
        label, format(x["matched_functions"], ","), format(x["total_functions"], ","),
        format(int(x["matched_code"]), ","), format(int(x["total_code"]), ","), x["matched_code_percent"],
        x["fuzzy_match_percent"])
    out = ["| | Functions (exact) | Code (exact) | Fuzzy |", "| --- | ---: | ---: | ---: |"]
    for cid, label in CAT_NAMES:
        if cid in cat:
            out.append(line(("**%s**" if cid == "core" else "%s") % label, cat[cid]["measures"]))
    out.append(line("**Shared level code**", cat["common"]["measures"]))
    out.append(line("**Level-specific code**", cat["levels"]["measures"]))
    for c in rep["categories"]:
        if c["id"].startswith("level_") and c["id"] != "level_code":
            out.append(line(c["name"], c["measures"]))
    out.append(line("**Total**", rep["measures"]))
    m = rep["measures"]
    out += ["", "Each distinct function counts once: frontbin's copy of the menus is the main image's, and a level "
            "function counts once however many of the %d levels have it. %s bytes (%.2f%%) are in units with "
            "nothing left to decompile." % (len(levels.read_table()), format(int(m["complete_code"]), ","),
                                            m["complete_code_percent"])]
    return "\n".join(out)


def main():
    levels.cli_version()
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true", help="rewrite progress/report.json")
    ap.add_argument("--check", action="store_true", help="fail if it is out of date")
    a = ap.parse_args()
    rep = report()
    text = text_of(rep)
    body = json.dumps(rep, indent=1) + "\n"
    print(text)
    if a.write:
        os.makedirs(os.path.dirname(report_path()), exist_ok=True)
        open(report_path(), "w", encoding="utf-8", newline="\n").write(body)
        print("wrote %s" % os.path.relpath(report_path(), ROOT))
    if a.check:
        import match_map
        problems = []
        if match_map.check():
            problems.append("config/%s/map.tsv does not cover src/ and nonmatching/ (tools/match_map.py --write)" % levels.V)
        if not os.path.exists(report_path()) or open(report_path(), encoding="utf-8").read() != body:
            problems.append("%s is out of date (python3 tools/progress.py --version %s --write)" % (
                os.path.relpath(report_path(), ROOT), levels.V))
        for p in problems:
            print("error:", p)
        sys.exit(1 if problems else 0)


if __name__ == "__main__":
    main()

# decomp-permuter

For near misses whose instructions are right but whose registers or order are not, OpenRAC's
[`tools/permuter`](https://github.com/OpenRAC/OpenRAC/tree/master/tools/permuter) runs [decomp-permuter](https://github.com/simonlindholm/decomp-permuter)
for this project, US and PAL. Its `rac4/ntsc` and `rac4/pal` profiles compile each candidate with
`tools/cc.sh` on a copy of the function's file (its `/* cflags: */` comment included) and count a
score 0 only when `tools/check_func.py --version us|pal` says MATCH. On macOS and Linux it runs the
compiler through wibo with a `wine` shim, without the container. It needs the release's `asm/`
(`python3 tools/asm_programs.py --version us main ...`). From an OpenRAC checkout:

```sh
OPENRAC_SOURCE_RAC4_NTSC=<this checkout> python3 tools/permuter run rac4/ntsc func_X --c nonmatching/.../func_X.c
```

Results are hints: rewrite the useful change by hand and check it with `tools/check_func.py` and
the build, as for any match.

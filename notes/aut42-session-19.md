# AUT-42 session 19

No C candidate was adopted.

- `func_00129D8C`: retail is a naked four-byte `jr $ra`; three valid empty C forms all add the compiler's delay-slot `nop` (8 bytes).
- `func_003FBE84`, `func_004053C4`, and `func_0040710C`: each is catalogued as a four-byte function but starts a much larger `alabel` block, so the configured boundary is not a standalone C target.
- `func_00470308`: the retail delay slot stores unset `$t4`, a documented assembly/non-C wall.
- `func_00141140`: void and return-forwarding wrappers both compile to a 28-byte call frame rather than the retail eight-byte tail jump.

All claims created by `aut42s19` were released. Scratch candidates and per-function NOTES remain in `build/try/` for later investigation.

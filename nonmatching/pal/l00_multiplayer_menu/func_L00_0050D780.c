/* Not matching yet on PAL: 13/18 positional words match (72.22%); 5 differ, size 72/72 bytes (delta 0). */
/* cflags: -O2 -G8 -fopt-stack -mno-check-zero-division */
/* Relocation fields are masked. Reproduce: tools/check_func.py --version pal func_L00_0050D780 nonmatching/pal/l00_multiplayer_menu/func_L00_0050D780.c --diff
 * Derived from rac3-decomp func_L39_004D1480 (GPL-3.0); RAC4 callee and buffer contracts remain unproved. */
#include "common.h"
typedef struct Obj Obj;


extern s32 func_L00_00532EF0(Obj *, s32 *, s32 *, s32, s32, s32);
extern void func_003FD538(Obj **);

s32 func_L00_0050D780(Obj *a0) {
    s32 buf[4];
    s32 v;
    s32 r;

    r = func_L00_00532EF0(a0, buf, &v, 0, 0, 0);
    func_003FD538(&a0);
    return r;
}

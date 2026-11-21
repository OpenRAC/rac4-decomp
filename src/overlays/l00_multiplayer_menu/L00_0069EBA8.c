#include "common.h"

typedef struct {
    u8 pad[0x14];
    s32 f14;
} Type2;
typedef struct {
    s32 f0;
    Type2 *f4;
} Type1;
extern Type1 D_00223148[];
extern s32 func_00697568(s32);
extern s32 func_00697588(s32);
extern s32 func_0069DF18(s32);
extern Type1 *func_L00_00698D80();
extern s32 func_L00_0069A5E0(s32, s32, s32, s32, s32, s32);

/* Look up the current entry twice and apply it, returning whether both steps succeeded. */
s32 func_L00_0069EBA8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Type1 *r;
    Type2 *n;
    s32 obj;
    s32 ok = 0;
    s32 one;
    s32 t0;
    s32 t1;

    if (D_00223148[0].f4) r = D_00223148; else r = func_L00_00698D80();
    n = r->f4;
    obj = func_00697568(n ? *(s32 *)((u32)n + ((u32)n->f14 << 2)) : 0);
    one = ok + 1;
    if (obj != 0) {
        ok |= one;
        if (D_00223148[0].f4) r = D_00223148; else r = func_L00_00698D80();
        n = r->f4;
        t0 = func_0069DF18(func_00697588(n ? *(s32 *)((u32)n + ((u32)n->f14 << 2)) : 0)) != 0;
        ok = ok & t0;
        if (D_00223148[0].f4) r = D_00223148; else r = func_L00_00698D80();
        n = r->f4;
        t1 = func_L00_0069A5E0(obj, func_00697588(n ? *(s32 *)((u32)n + ((u32)n->f14 << 2)) : 0),
                                arg0, arg1, arg2, arg3) != 0;
        ok = ok & t1;
    }
    return ok;
}

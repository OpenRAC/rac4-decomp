#include "common.h"

typedef int Vec128 __attribute__((mode(TI)));

typedef struct Obj Obj;
typedef struct ObjVt {
    u8 pad0[0x3C];
    Vec128 (*f3C)(s32);
} ObjVt;
typedef struct Vars {
    u8 pad0[0x1D8];
    s32 f1D8;
    u8 pad1DC[0x204 - 0x1DC];
    ObjVt *f204;
} Vars;
typedef struct Info {
    u8 pad0[0x10];
    s32 f10;
} Info;
typedef struct Type0 {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
} Type0;

extern s32 func_00596F28(s32);
extern Info *func_005A16E8(s32);
extern s32 func_L00_005A38F8(Vec128 *, u8 *, s32, s32, s32);
extern void func_L00_005F1778(s32, u8 *, s32);
extern Type0 D_00242340;
extern u8 *D_003660F8[10];

s32 func_L01_00501688(u8 *moby) {
    u8 buf[16];
    Vec128 v;
    Vars *vars;
    Info *info;
    u8 *p;
    s32 i;
    s32 found;

    found = 0;
    vars = *(Vars **)(moby + 0xAC);
    info = func_005A16E8(vars->f1D8);
    func_L00_005F1778(info->f10, buf, 0);
    v = vars->f204->f3C(vars->f1D8);
    for (i = 0, p = D_003660F8[0]; i < 10; p = D_003660F8[++i]) {
        if (p != NULL && *(s32 *)(p + 0x2EF0) == info->f10 && *(u8 **)(p + 0x2EF4) != NULL) {
            found = *(s32 *)(*(u8 **)(p + 0x2EF4) + 0x2B0);
        }
    }
    if (func_L00_005A38F8(&v, buf, 2, vars->f1D8, 0) == 0 || D_00242340.f1C == 0 ||
        (D_00242340.f18 != 0 &&
         (func_00596F28(D_00242340.f18) != 0 || (found != 0 && D_00242340.f18 == found)))) {
        return 1;
    }
    return 0;
}

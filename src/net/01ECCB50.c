/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x400]; char *f400; s32 f404; char _p408[0x58]; s32 f460; char _p464[0x14]; s32 f478; s32 f47C; s32 f480; s32 f484; } Obj_488;
typedef struct { s32 f0; u8 f4; s32 f8; s32 fC; s32 _p10[9]; s32 f34; s32 f38; s8 *f3C; } Req_40;
typedef struct { s32 _p[12]; } Res_30;
typedef struct { char _p0[0x120]; s32 f120; char _p124[0x14]; s32 f138; char _p13c[4]; s32 f140; s32 f144; } Tab;
typedef struct { char _p0[0x124]; s32 f124; s32 f128; char _p12c[0x1c]; s32 f148; s32 f14C; s32 f150; s32 f154; } Ctx;
extern void *func_0011A518(void *, s32, s32);
extern void func_01EA0368(void *, s32);
extern s32 func_01EA1270(Req_40 *, Res_30 *, s32);
extern void func_01EA3B10(void *, s32);
extern s32 func_01EA4570(u32 index);
extern s32 func_01EA4EE0(s32 arg0);
extern void func_01EC8FF0(void *arg0);
extern s32 func_01EC97B8(void);
extern void func_01ECA098();
extern s32 func_01ECC958(void *arg0, s32 arg1);
extern s32 func_01ECCA90(void);
extern Ctx *D_00167F38;
extern Tab D_001B7258;

// Resets the object arg0 and the global state at D_001B7258; returns 0 once reset, else 0x17 or 0x10.
s32 func_01ECCB50(Obj_488 *arg0) {
    Req_40 q;
    Res_30 res;
    s8 sp70;
    s32 i;
    s32 v;

    if (arg0 == 0) {
        return 0x17;
    }
    if (D_001B7258.f138 == 0) {
        return 0x10;
    }
    func_01EA3B10(arg0, 0);
    sp70 = func_01EA4EE0(arg0->f404);
    func_0011A518(&q, 0, sizeof(q));
    q.f4 = 0x50;
    q.fC = -1;
    q.f34 = arg0->f460;
    q.f8 = 0x12;
    q.f38 = 1;
    q.f3C = &sp70;
    q.f0 = (s32)arg0;
    func_01EA1270(&q, &res, 0);
    func_01ECCA90();
    func_01ECA098();
    func_01EC8FF0(arg0);
    D_001B7258.f138 = 0;
    D_00167F38->f124 = 0;
    D_00167F38->f128 = 0;
    if (arg0->f400 == 0) {
        return 0x17;
    }
    ((s32 *)arg0->f400)[4] = 0;
    ((s32 *)arg0->f400)[3] = 2;
    ((s32 *)arg0->f400)[5] = 0;
    func_01EA0368(arg0, -1);
    i = 0;
    do {
        v = func_01EA4570(i);
        i++;
        if (v != 0) {
            func_01ECC958((void *)v, 0x100);
            arg0->f478 = 0;
            arg0->f47C = 0;
            arg0->f480 = 0;
            arg0->f484 = 0;
        }
    } while (i < 4);
    func_01EC97B8();
    D_001B7258.f144 = 0;
    D_001B7258.f120 = 0;
    D_00167F38->f154 = 0;
    D_001B7258.f140 = 0;
    D_00167F38->f14C = 0;
    D_00167F38->f150 = 0;
    D_00167F38->f148 = 0;
    return 0;
}

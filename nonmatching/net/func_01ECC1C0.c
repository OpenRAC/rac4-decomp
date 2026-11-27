/* Not matching yet: BYTES 1/296 (tools/try_func.py func_01ECC1C0 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 w[6]; } Ring;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
    char _p6[0xA];
    s32 f10;
    s32 f14;
    s32 f18;
    char _p1C[0x10];
    Ring q;
} Ent;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 _p5;
    s16 f6;
    s16 f8;
    s16 fA;
} Hdr;

extern void func_0011A370(void *, void *, s32);
extern s32 func_01EA70B0(Ring *arg0, s32 arg1);
extern s32 func_01EA72C8(Ring *arg0, s32 *arg1);
extern s32 func_01EA73A8(Ring *arg0, s32 *arg1);
extern Ent *func_01EC9A28(u32 i);

s32 func_01ECC1C0(s32 arg0, u32 arg1, s32 arg2)
{
    Hdr s;
    s32 sp10;
    s32 sp14;
    Ent *e;
    s32 d0;
    s32 d1;

    sp14 = 0;
    sp10 = 0;
    if (arg0 == 0)
        return 0;
    if (arg2 <= 0)
        return 0;
    e = func_01EC9A28(arg1);
    if (e == 0)
        return 0;
    s.f0 = arg1;
    s.f1 = e->f5;
    s.f2 = e->f3;
    s.f3 = e->f1;
    s.f4 = e->f2;
    s.fA = arg2;
    d0 = e->f14 - e->f10;
    d1 = e->f18 - e->f10;
    s.f6 = d0;
    s.f8 = d1;
    func_0011A370((void *)arg0, &s, 0xC);
    if (func_01EA73A8(&e->q, &sp10) != 0)
        return 0;
    if (sp10 != 0) {
        if (func_01EA70B0(&e->q, 1) != 0)
            return 0;
        func_0011A370((void *)e->f10, (void *)e->q.w[4], e->q.w[2]);
    }
    if (func_01EA72C8(&e->q, &sp14) != 0)
        return 0;
    func_0011A370((void *)(arg0 + 0xC), (void *)sp14, arg2);
    return arg2 + 0xC;
}

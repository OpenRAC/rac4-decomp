/* Not matching yet: BYTES 6/316 (tools/try_func.py func_01ED9820 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 a, b, c, d, e, f; } Type1;

typedef struct Arg0 Arg0;
struct Arg0 {
    u16 f0;
    char _p2[2];
    s32 f4;
    s32 f8;
    s32 fC;
    char _p10[0x10];
    s32 f20;
};

typedef struct {
    s32 f0;
    u16 f4;
    char _p6[2];
    s32 f8;
    s8 fC;
} Tmp;

extern s32 (*D_001994D0[])();
extern s32 (*D_001995E8[])();

extern Type1 func_01EDB3E0(s32, s32, s32, s32, s32, s32);
extern s32 func_01EDA5C0(s32, s32, void *);

s32 func_01ED9820(Arg0 *arg0, s32 arg1, s32 *arg2)
{
    Tmp tmp;
    Type1 sp10;
    s32 (*p)();
    s32 sz;
    u8 *buf;
    s32 v;
    s32 w;

    sp10 = func_01EDB3E0(0, 0, 4, 0x21, -1, 1 << arg0->fC);
    p = D_001995E8[7];
    sz = p(0x10);
    buf = __builtin_alloca((sz + 0xF) & ~0xF);
    D_001995E8[1](buf, p(0x10));
    tmp.f4 = arg0->f0;
    tmp.fC = arg1;
    tmp.f8 = arg0->fC;
    tmp.f0 = D_001994D0[0](arg0->f20);
    v = -0x15;
    if (tmp.f0 == 0) {
        return v;
    }
    v = func_01EDA5C0(1, (s32)buf, &tmp);
    if (v != 0) {
        return v;
    }
    v = D_001995E8[3](buf, &sp10);
    if (v != 0) {
        return v;
    }
    if (arg2 != 0) {
        w = *(s32 *)(buf + 0x34);
        *arg2 = w;
        arg0->f8 = w;
    }
    return v;
}

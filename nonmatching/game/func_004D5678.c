/* Not matching yet: BYTES 7/320 (tools/try_func.py func_004D5678 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    char pad[0x34];
    s32 *f34;
    char pad2[0x1C];
    s32 f54;
} Cfg;

typedef struct {
    char pad[8];
    s32 *f8;
} Ent;

typedef struct {
    char pad0[4];
    s32 f4;
    char pad1[0x13A8];
    u8 b13B0;
    u8 b13B1;
} Big;

extern Cfg D_31CCC4;
extern Big D_31B9B8;
s32 D_0021FBB4 = 0;
s32 D_0021FBB0 = 0;
extern s32 func_004D5608(void *);
extern s32 func_004E7000(s32 *, s32, s32);
extern void func_00497980(s32);

void func_004D5678(s32 arg0)
{
    Cfg *cfg;
    Ent *e;
    s32 *s0;
    s32 v;
    s32 prev;
    s32 cur;

    if (arg0 == 0)
        return;

    cfg = &D_31CCC4;
    e = 0;
    if (cfg->f54 >= 0) {
        e = (Ent *)(cfg->f54 * 0x18 + (s32)cfg->f34);
    }
    s0 = e->f8;

    if (func_004D5608(s0) == 0) {
        D_31B9B8.b13B1 = 1;
        D_31B9B8.b13B0 = 1;
    }

    func_004E7000(s0, 0, 0);
    D_31B9B8.f4 |= 5;

    v = s0[0];
    if ((u32)(v - 0xA) < 2) {
        prev = (v == 0xB) ? D_0021FBB4 : D_0021FBB0;
        cur = s0[1];
        if (prev != cur) {
            if (s0[0] == 0xB)
                D_0021FBB4 = cur;
            else if (s0[0] == 0xA)
                D_0021FBB0 = cur;
            if (s0[2] > 0)
                func_00497980(0x21);
            else
                func_00497980(0x16);
        } else {
            func_00497980(4);
        }
    } else if (v == 8) {
        func_00497980(0x3A);
    } else if (v == 9) {
        func_00497980(0x39);
    }
}

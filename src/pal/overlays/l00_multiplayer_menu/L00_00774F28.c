#include "common.h"
#include "pal/global_002234A4.h"
#include "pal/profile_001721E0.h"

typedef struct Ctx {
    u8 x0;
    u8 pad1[0xF];
    s32 x10;
    s32 x14;
    u8 pad18[0x4];
    u8 x1C;
} Ctx;

extern s32 func_0015B568(void);
extern void func_0015A080(void);
extern s32 func_0012E370(void);
extern s64 func_0012FEB0(s32, s64);

// Add PAL C for func_L00_00774F28
s32 func_L00_00774F28(u8 *st) {
    Ctx *c;
    u8 *g;
    u8 *h;
    s32 ok1;
    s32 ok2;

    c = D_002234A4;
    ok1 = 1;
    if (st[4] != 0) {
        g = (u8 *)&D_001721E0;
        do {
            if (func_0015B568() != 0 || *(s32 *)(g + 0x2C4) != 0) {
                c->x10 = 0x38;
                if (c->x14 == 0) {
                    c->x14 = 0x38;
                }
                ok1 = 0;
            }
            c->x1C = 1;
            func_0015A080();
            c->x1C = 0;
            if ((s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(st + 0xC) <= 15000) {
                continue;
            }
            ok1 = 0;
            break;
        } while (st[4] != 0);
    }
    st[4] = 0;
    ok2 = 1;
    if (st[0x12] != 0) {
        h = (u8 *)&D_001721E0;
        do {
            if (func_0015B568() != 0 || *(s32 *)(h + 0x2C4) != 0) {
                c->x10 = 0x38;
                if (c->x14 == 0) {
                    c->x14 = 0x38;
                }
                ok2 = 0;
            }
            c->x1C = 1;
            func_0015A080();
            c->x1C = 0;
            if ((s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(st + 0x18) <= 15000) {
                continue;
            }
            ok2 = 0;
            break;
        } while (st[0x12] != 0);
    }
    st[0x12] = 0;
    return ok1 != 0 || ok2 != 0;
}

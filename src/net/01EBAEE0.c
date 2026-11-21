/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } Item_14;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; u8 pad14[0x50 - 0x14]; } Item_50;
typedef struct { s32 f0; u8 pad4[0x184 - 4]; Item_50 *f184; u8 pad188[0x194 - 0x188]; s32 *f194; u8 pad198[0x19C - 0x198]; u16 f19C; } Ctx_19C;
extern s32 func_01EBE908(s32, s32 *, u32, s32, s32);
// Fills the key table at c->f194 from the entry list (or from the 0x50-byte records at c->f184) and passes the count on.
s32 func_01EBAEE0(Ctx_19C *c, Item_14 **arg1, u32 n, u16 d, s32 e5) {
    Item_50 *s;
    u32 i;
    s32 r;
    if (arg1 != NULL) {
        for (i = 0; i < n; i++) {
            Item_14 *e = arg1[i];
            if (e->f4 != 0 && e->fC != 0) {
                c->f194[i] = e->f4;
            } else if (arg1[i]->f8 != 0 && arg1[i]->f10 != 0) {
                c->f194[i] = arg1[i]->f8;
            } else {
                c->f194[i] = 0;
            }
        }
    } else {
        n = 0;
        s = c->f184;
        for (i = 0; i < c->f19C; i++) {
            if ((u32)(s->f0 - 3) < 2U) {
                if (s->f4 != 0 && s->fC != 0) {
                    c->f194[n++] = s->f4;
                } else if (s->f8 != 0 && s->f10 != 0) {
                    c->f194[n++] = s->f8;
                }
            }
            s++;
        }
    }
    if (n != 0) {
        r = func_01EBE908(c->f0, c->f194, n, d, e5);
    } else {
        r = 0xD2F3;
    }
    return r;
}

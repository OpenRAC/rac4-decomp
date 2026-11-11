/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C1318 (src/levels/39_multiplayer_menu/L39_004C0E50.c, GPL-3.0), the same code in both games. */

extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
typedef struct P_004C1318 {
    u8 pad0[0x6C];
    s32 len;
    u8 data[1];
} P_004C1318;
typedef struct B_004C1318 {
    s32 pad0;
    u8 *buf;
} B_004C1318;
typedef struct Type1 {
    u8 pad0[0x30];
    s32 state;
    u8 pad34[0x3C - 0x34];
    B_004C1318 *b;
    s32 pos;
    u8 pad44[0x50 - 0x44];
    P_004C1318 *p;
} Type1;
extern s32 func_L00_005010B0(Type1 *, u8 *, s32);
extern s32 func_L00_00501D70(Type1 *, s32, s32);
extern void func_L00_00501F00(Type1 *, s32);
extern s32 func_0011A2DC(void *, void *, s32);
s32 func_L00_004FD118(Type1 *s) {
    u8 *buf = s->b->buf;
    s32 n;
    if (s->state == 0x1060) {
        n = func_L00_005010B0(s, buf + s->pos, 1 - s->pos);
        if (n < 1 - s->pos) {
            return func_L00_00501D70(s, 0x6E, n);
        }
        s->pos = 0;
        s->state = 0x1061;
        if (buf[0] != 5) {
            if (buf[0] != 0) {
                func_L00_00501F00(s, 0);
                func_L00_004F84C8(0x14, 0x6E, 0xD4, 0, 0);
            } else {
                func_L00_004F84C8(0x14, 0x6E, 0xC8, 0, 0);
            }
            return -1;
        }
    }
    n = func_L00_005010B0(s, buf + s->pos, s->p->len - s->pos);
    if (n < s->p->len - s->pos) {
        return func_L00_00501D70(s, 0x6E, n);
    }
    if (func_0011A2DC(buf, s->p->data, s->p->len)) {
        func_L00_00501F00(s, 0);
        func_L00_004F84C8(0x14, 0x6E, 0x88, 0, 0);
        return -1;
    }
    return 1;
}

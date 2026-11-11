/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Sock {
    u8 pad0[0xA4];
    s32 fA4;
    s32 fA8;
    s32 fAC;
    u8 padB0[0xE8 - 0xB0];
    s32 fE8;
    s32 fEC;
    s32 fF0;
    s32 fF4;
} Sock;

typedef struct Conn {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x4];
    s32 f18;
    u8 pad1C[0x54 - 0x1C];
    s32 f54;
} Conn;

extern s32 *func_0011A1A0(void);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s32 func_L00_00516AB0(s32, s32, s32);

s32 func_L00_00505368(Conn *c, s32 arg1, s32 arg2, s32 arg3) {
    Sock *s;
    s32 r;

    s = ((Sock *)c->f54);
    if (arg3 < s->fE8 || s->fF4 != arg2 || s->fEC != arg1) {
        func_L00_004F84C8(0x14, 0xA0, 0x7F, 0, 0);
        return -1;
    }
    while (1) {
        *func_0011A1A0() = 0;
        if (c->f10 != 0) {
            c->f18 = 2;
            r = func_L00_00516AB0(c->f10, ((Sock *)c->f54)->fAC + ((Sock *)c->f54)->fA8, ((Sock *)c->f54)->fA4);
        } else {
            func_L00_004F84C8(0x14, 0xA0, 0x80, 0, 0);
            r = -1;
        }
        if (r == ((Sock *)c->f54)->fA4) {
            ((Sock *)c->f54)->fA4 = 0;
            c->f18 = 1;
            return ((Sock *)c->f54)->fF0;
        }
        if (r <= 0) {
            return r;
        }
        ((Sock *)c->f54)->fA8 += r;
        ((Sock *)c->f54)->fA4 -= r;
    }
}

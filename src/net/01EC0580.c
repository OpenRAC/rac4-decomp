/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b[8]; } A8;
typedef struct { s32 f0; char _p4[0x58]; s32 f5C; char _p60[0x34]; A8 f94; s32 f9C; } Conn;
extern s32 func_01EA7BC8(s32, A8 *, s32 *, s32, s32, u32 *);
extern s32 func_01EA8BD0(A8, A8);
extern void func_01EC0628(Conn *, A8, s32, u32);
s32 func_01EC0580(Conn *c) {
    A8 addr;
    s32 x;
    u32 cnt = 0;
    do {
        cnt = 0;
        if (func_01EA7BC8(c->f0, &addr, &x, c->f5C, 0x5AA, &cnt) == 0) {
            if (cnt == 0) {
                break;
            }
            if (cnt >= 2) {
                if (func_01EA8BD0(addr, c->f94) == 0 || x != c->f9C) {
                    func_01EC0628(c, addr, x, cnt);
                }
            }
        }
    } while (cnt != 0);
    return 0;
}

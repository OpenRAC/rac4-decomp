/* cflags: @ee29 */
#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    u8 pad28[0x10];
    s32 f38;
} Buf;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[4];
    s32 f18;
    u8 pad1C[0x34];
    s32 f50;
} Conn;

extern s32 *func_0011A1A0(void);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s32 func_L00_00516AB0(s32, s32, s32);

s32 func_L00_00501980(Conn *arg0, s32 arg1, s32 arg2) {
    s32 n;

    if (arg2 < ((Buf *)arg0->f50)->f14 || ((Buf *)arg0->f50)->f18 != arg1) {
        func_L00_004F84C8(0x14, 0xD5, 0x7F, 0, 0);
        return -1;
    }
    while (1) {
        *func_0011A1A0() = 0;
        if (arg0->f10 != 0) {
            arg0->f18 = 2;
            n = func_L00_00516AB0(arg0->f10, ((Buf *)arg0->f50)->f38 + ((Buf *)arg0->f50)->f1C, ((Buf *)arg0->f50)->f20);
        } else {
            func_L00_004F84C8(0x14, 0xD5, 0x104, 0, 0);
            n = -1;
        }
        if (n == ((Buf *)arg0->f50)->f20) {
            ((Buf *)arg0->f50)->f20 = 0;
            arg0->f18 = 1;
            return ((Buf *)arg0->f50)->f24;
        }
        if (n <= 0) {
            return n;
        }
        ((Buf *)arg0->f50)->f1C += n;
        ((Buf *)arg0->f50)->f20 -= n;
    }
}

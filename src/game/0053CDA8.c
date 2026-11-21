/* cflags: -mno-split-addresses */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));
typedef struct { u8 pad[0xBE]; u8 b0 : 3; u8 b3 : 1; u8 b4 : 1; u8 b5 : 3; } Type1;
extern void func_00438F58(s32 arg0, void *arg1);
extern void func_0044E060(void *arg0, void *arg1, u128 arg2, s64 arg3);
extern void func_00496E78();
extern s32 D_0021EDD4[];
extern s32 D_0021EDD8[];
extern u8 D_221280[];

// Starts an action of object arg1 on the object arg0: records both and runs the handlers.
void func_0053CDA8(u8 *arg0, u8 *arg1) {
    s32 r;

    if (*(u8 **)(arg0 + 0x32C) != arg1) {
        func_0044E060(D_221280, arg1, *(u128 *)(arg1 + 0xA0), 0);
    }
    if (arg1[0x266D] != 0) {
        func_00438F58(0, *(void **)(arg1 + 0x2F00));
        r = ((s32 (*)(u8 *))(*(void **)(*(u8 **)(arg1 + 0x14) + 0x4C)))(arg1);
        func_00496E78(r, 1, 0);
        if (D_0021EDD4[0] == 0 && D_0021EDD8[0] == 1) {
            r = ((s32 (*)(u8 *))(*(void **)(*(u8 **)(arg1 + 0x14) + 0x4C)))(arg1);
            func_00496E78(r, 8, 0);
        }
    }
    *(u8 **)(arg0 + 0x2BC) = arg1;
    *(s32 *)(arg0 + 0x32C) = 0;
    *(s32 *)(arg1 + 0x2F18) = 6;
    *(u8 **)(arg1 + 0x2EF4) = arg0;
    *(s32 *)(arg1 + 0x2EF8) = 0;
    ((void (*)(u8 *, s32, s32, s32, s32))(*(void **)(*(u8 **)(arg1 + 0x14) + 0x3C)))(arg1, 0x31, 1, 0, 1);
    arg0[0x2FD] = 1;
    if (*(s32 *)(arg0 + 0x2B8) == 0) {
        *(u8 **)(*(u8 **)(arg0 + 0x2B0) + 0xB8) = *(u8 **)(arg1 + 0x2EF0);
    }
    *(s32 *)(arg0 + 0x2D8) &= 0xFFFFFBFF;
    if (*(s32 *)(arg1 + 0x2F14) == 0) {
        (*(Type1 **)(arg0 + 0x2B0))->b4 = 1;
        (*(Type1 **)(arg0 + 0x2B0))->b3 = 0;
    } else if (*(s32 *)(arg1 + 0x2F14) == 1) {
        (*(Type1 **)(arg0 + 0x2B0))->b3 = 1;
        (*(Type1 **)(arg0 + 0x2B0))->b4 = 0;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x2EF0) + 0x98) = 0;
    if (arg1[0x266D] == 0) {
        if (!(*(s32 *)(arg0 + 0x2D8) & 0x04000000)) {
            arg1[0x2662] = 1;
        }
    } else {
        arg1[0x2662] = 1;
    }
}

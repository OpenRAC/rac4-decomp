/* Not matching yet: BYTES 5/696 (tools/try_func.py func_004BB460 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u8 pad10[0x11];
    u8 f21;
    u8 f22;
    u8 f23;
    u8 f24;
    u8 f25;
} Stats171B40;

void func_0045DC60(s32, s32);

static inline s32 testBit(s32 v, s32 n) {
    return (v >> n) & 1;
}
extern Stats171B40 D_00171B40[];
extern s32 D_00171C14[];
extern s32 D_0021DE10;
extern u8 D_001F87F0[];

void func_004BB460(void) {
    if (testBit(D_001F87F0[0xC0C], 3)) {
        func_0045DC60(0x294F, 0x2C6);
        func_0045DC60(0x2F98, 0x66E);
    }
    if ((testBit(D_001F87F0[0x2A34], 3)) && D_0021DE10 != 0xF) {
        func_0045DC60(0x3310, 0x75B);
        if (D_00171C14[0] & 0x20000000) {
            func_0045DC60(0x2962, 0x2D9);
        }
    }
    if (testBit(D_001F87F0[0x604], 3)) {
        func_0045DC60(0x2F97, 0x66D);
    }
    if ((testBit(D_001F87F0[0x2A34], 1)) && !(testBit(D_001F87F0[0x2A34], 3))) {
        func_0045DC60(0x3379, 0x7C4);
    }
    if ((testBit(D_001F87F0[0x2128], 1)) && !(testBit(D_001F87F0[0x2128], 3))) {
        func_0045DC60(0x333C, 0x787);
    }
    if ((testBit(D_001F87F0[0x1518], 1)) && !(testBit(D_001F87F0[0x1518], 3))) {
        func_0045DC60(0x2F37, 0x61A);
    }
    if ((testBit(D_001F87F0[0x1214], 1)) && !(testBit(D_001F87F0[0x1214], 3))) {
        func_0045DC60(0x2F34, 0x618);
    }
    if ((testBit(D_001F87F0[0xF10], 1)) && !(testBit(D_001F87F0[0xF10], 3))) {
        func_0045DC60(0x2F30, 0x614);
    }
    if ((testBit(D_001F87F0[0xC0C], 1)) && !(testBit(D_001F87F0[0xC0C], 3))) {
        func_0045DC60(0x2F33, 0x617);
    }
    if (D_00171B40[0].fC >= 15000 && D_00171B40[0].f23 >= 4) {
        func_0045DC60(0x2F43, 0x625);
    }
    if (D_00171B40[0].fC >= 50000 && D_00171B40[0].f21 >= 2) {
        func_0045DC60(0x2F4A, 0x62C);
    }
    if (D_00171B40[0].fC >= 100000 && D_00171B40[0].f24 >= 2) {
        func_0045DC60(0x2FA2, 0x677);
    }
    if (D_00171B40[0].fC >= 150000 && D_00171B40[0].f25 >= 2) {
        func_0045DC60(0x2F91, 0x667);
    }
}

#include "common.h"

extern s32 func_0047D278(s32 arg0);
extern void *func_0047D4E8(void);
extern s32 func_004CCDC0(s32);
extern s32 func_004CCFD8(s32 i);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern s32 func_00548DA0(s32, s32);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_0021DE10;
extern s32 D_0021F198;
extern s32 D_00171C14[];

s32 func_004CC7A0(s32 arg0) {
    u8 *p;
    u8 *s0;

    if ((u32)(arg0 - 8) < 2) {
        return 1;
    }
    if (arg0 < 8) {
        if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
            s0 = func_00510BE8(func_00505B20());
            return func_00548DA0(*(s32 *)(s0 + 0x26E4), func_004CCFD8(arg0));
        }
        p = func_0047D4E8();
        if (p != 0 && *(s32 *)(p + 0x1D0) == 0) {
            return 0;
        }
        if (D_0021DE10 == 1 && D_0021F198 == 0 && !(D_00171C14[0] & 0x10000000)) {
            return 0;
        }
        return func_0047D278(func_004CCDC0(arg0));
    }
    s0 = func_00510BE8(func_00505B20());
    return func_00548DA0(*(s32 *)(s0 + 0x26E4), func_004CCDC0(arg0));
}

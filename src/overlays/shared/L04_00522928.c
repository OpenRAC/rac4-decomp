#include "common.h"

extern s32 D_0021EA58;
extern s32 D_0021DE10;
extern u8 D_1F87F0[];
s32 func_L01_0056FE70();

/* If the current slot's entry flag at +9 is clear, forward to func_L01_0056FE70. */
s32 func_L04_00522928(s16 a0, s16 a1, s32 a2) {
    if (D_0021EA58 != -1) {
        if (D_1F87F0[D_0021EA58 * 12 + ((D_0021DE10 - 1) % 20) * 0x304 + 9] == 0) {
            return func_L01_0056FE70(a0, a1, a2);
        }
    }
    return 0;
}

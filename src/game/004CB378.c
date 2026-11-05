#include "common.h"

extern void func_00437CD8(s32);
extern s32 func_00465C08(void);
extern s32 func_004CA8E8();
extern u8 D_00171D38[];
extern s32 D_0021DE10;
extern s32 D_0021EDBC;
extern s32 D_002212E0;
s32 D_0021FA30 = 0;

// Updates mode state when the current mode is not 0x16
s32 func_004CB378(void) {
    if (func_00465C08() != 0x16) {
        D_0021EDBC = 1;
        if (D_0021DE10 == 0xF || D_0021DE10 == 0x23) {
            D_0021DE10 = 1;
        }
        if (func_004CA8E8() != 0) {
            D_0021DE10 = D_0021DE10 % 20 + 20;
        } else {
            D_0021DE10 = D_0021DE10 % 20;
        }
        D_002212E0 = D_0021DE10;
        if (D_0021FA30 != D_00171D38[0xBD]) {
            func_00437CD8(D_00171D38[0xBD]);
            D_0021FA30 = D_00171D38[0xBD];
        }
    }
    return 0;
}

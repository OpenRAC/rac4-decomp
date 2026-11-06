#include "common.h"

extern void func_00498CF8(void);
extern s32 func_00505B20(void);
extern void func_0049B2F8(s32, s32);
extern s32 D_0021F198;
extern u8 D_0021F93B;
extern u8 D_0021F8E8;
extern u8 D_0021F939;
extern u8 D_0021F93A;
extern u8 D_0021F938;

/* Unless D_0021F198 is -1: calls func_00498CF8, clears five flag bytes and calls func_0049B2F8(func_00505B20(), -1). */
void func_004CF040(void) {
    if (D_0021F198 != -1) {
        func_00498CF8();
        D_0021F93B = 0;
        D_0021F8E8 = 0;
        D_0021F939 = 0;
        D_0021F93A = 0;
        D_0021F938 = 0;
        func_0049B2F8(func_00505B20(), -1);
    }
}

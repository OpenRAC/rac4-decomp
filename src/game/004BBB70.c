#include "common.h"

extern void func_0049B1A0(s32 arg0, s32 arg1);
extern void func_0049B208(s32 arg0);
extern s32 func_00505B20(void);
extern s32 D_0021F198;
extern u8 D_0021F938;
extern u8 D_0021F939;
extern u8 D_0021F93A;

/* Depending on D_0021F198 and the byte D_0021F939, update the flag bytes
 * D_0021F938 / D_0021F93A and call func_0049B1A0 or func_0049B208. */
void func_004BBB70(void) {
    s32 index = func_00505B20();

    if (D_0021F198 == -1) {
        if (D_0021F939 == 0) {
            D_0021F938 = 1;
            func_0049B1A0(index, 3);
            return;
        }
        goto set_flag;
    }
    if (D_0021F939 == 0) {
        D_0021F93A = 0;
        D_0021F938 = 0;
        func_0049B208(index);
        return;
    }
set_flag:
    D_0021F93A = 1;
    func_0049B208(index);
}

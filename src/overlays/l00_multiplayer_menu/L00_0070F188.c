#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_L00_005C9F50(s32);
extern void func_L00_007106C0(void);
u8 D_00220B14 = 0;
u8 D_00220B15 = 0;
extern s32 D_003B1738[];
extern u8 D_003F40B8[];

s32 func_L00_0070F188(s32 arg0, u8 *arg1) {
    func_L00_007106C0();
    if (arg0 == 0) {
        if (D_00220B14 != 0) {
            if (*(s32 *)(arg1 + 8) == D_003B1738[0]) {
                func_0011D920(D_003F40B8, func_L00_005C9F50(0x3406), arg1 + 0x1B);
                D_00220B15 = 0;
                D_00220B14 = 0;
            }
        }
    }
    return 2;
}

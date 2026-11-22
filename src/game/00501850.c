#include "common.h"
f32 D_00222040 = 0;
s32 D_00222044 = 0;
u8 D_00220AC0 = 0;
extern f32 D_00237240[];
extern s32 D_0021DEC4, D_0021DDB4;
extern u8 D_0021EE18;
extern void func_00447BA8(void);
extern void func_004E7990(s32, u64, s32);
void func_00501850(void) {
    D_00222040 = D_00237240[44];
    D_00237240[44] = 0.62f;
    func_00447BA8();
    func_004E7990(0x47, 0x33001, 0);
    D_00222044 = D_0021DEC4;
    if (D_0021DDB4 != 0) {
        D_00220AC0 = 1;
    } else if (D_0021EE18 != 0) {
        D_00220AC0 = 1;
    } else {
        D_00220AC0 = 0;
    }
}

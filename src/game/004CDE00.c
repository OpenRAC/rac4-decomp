#include "common.h"

extern s32 func_0045E038(s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004CE068(u8 *arg0);
extern s32 func_004CE410(s32 i);
extern s32 func_00505238(s32 handle, u32 value);
extern s32 func_00505328(s32 handle, u32 value);

/* Looks up handles for the two records of arg1 and sends their values, choosing the second send by arg2 against arg0's field at 0x54. */
void func_004CDE00(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 *temp_s3;
    u8 *temp_s4;

    temp_s3 = (s32 *)(arg1 + 4);
    temp_s4 = *(u8 **)(arg1 + 8);
    temp_s0 = func_004A1A60(temp_s3, 2);
    func_00505238(temp_s0, func_0045E038(func_004CE410(*(s32 *)(temp_s4 + 8))));
    if (arg2 == *(s32 *)(arg0 + 0x54)) {
        func_00505328(func_004A1A60(temp_s3, 2), 0x80D0D0D0);
    } else {
        temp_s0_2 = func_004A1A60(temp_s3, 2);
        func_00505328(temp_s0_2, func_004CE068(temp_s4));
    }
}

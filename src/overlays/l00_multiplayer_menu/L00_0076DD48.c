/* cflags: -mno-split-addresses */
#include "common.h"

s32 func_0011A518(void *, s32, s32);
s32 func_0011AB04(s32);
s32 func_L00_005C1758(void *, s32, s32);
s32 func_L00_0076E478(void *, s32);

void func_L00_0076DD48(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_s1;

    temp_s1 = (void *)((u32)arg0 + 0x20);
    func_0011A518(temp_s1, 0, 0xAC);
    func_L00_005C1758(temp_s1, arg1, func_0011AB04(arg1));
    *(s32 *)((u32)arg0 + 0xCC) = arg2;
    *(s32 *)((u32)arg0 + 0xD0) = arg3;
    func_L00_0076E478(arg0, 6);
}

/* cflags: -mno-split-addresses */
#include "common.h"

/* Pass the object and its fields at +0x10 and +0xF0, with a stack copy of the object, to func_L01_00550790. */
extern s32 func_L01_00550790(s32 unused0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern u8 D_222B20[];

void func_L01_004696B0(void *arg0) {
    func_L01_00550790((s32)D_222B20, (s32)arg0, (s32)arg0 + 0x10, (s32)arg0 + 0xF0, (s32)&arg0, 1, 0);
}

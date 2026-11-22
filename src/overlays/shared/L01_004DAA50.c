/* cflags: -mno-split-addresses */
#include "common.h"
extern u8 D_00222B28[];
extern s32 func_00452D98(u8 *, s32, f32, f32);
extern void func_L01_004DA300(void *, f32);
extern void func_L01_004DA638(void *, f32, f32);
void func_L01_004DAA50(u8 *arg0) {
    u8 *entry = *(u8 **)(arg0 + 0xAC);
    if (entry != 0 && func_00452D98(D_00222B28, (s32)(entry + 0x20), (f32)*(s16 *)(arg0 + 0x32), *(f32 *)(entry + 0xC) * 2.0f) != -1) {
        func_L01_004DA300(arg0, 1.0f);
        func_L01_004DA638(arg0, 1.0f, *(f32 *)(entry + 8));
    }
}

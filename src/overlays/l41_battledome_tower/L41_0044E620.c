/* cflags: -mno-split-addresses */
#include "common.h"
typedef int u128 __attribute__((mode(TI)));
extern u8 D_002225A8[];
extern s32 func_004D4480(u8 *, s32, f32, f32);
extern void func_L41_0044DFC8(void *, f32);
void func_L41_0044E620(u8 *arg0) {
    u8 *entry = *(u8 **)(arg0 + 0xAC);
    if (entry != 0 && func_004D4480(D_002225A8, (s32)(entry + 0x20), (f32)*(s16 *)(arg0 + 0x32), (f32)*(f32 *)(entry + 0x4) * 2.0f) != -1) {
        func_L41_0044DFC8(arg0, *(f32 *)(entry + 0));
    }
}

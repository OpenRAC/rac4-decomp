/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern s32 D_0021DE40;
extern s16 D_0024798C[];
extern s32 func_L15_004D8480(void *, s32, ...);
extern s32 func_0045DFC8(s16, s16, s16, s32, f32, f32, f32, f32);
/* Select an event from the supplied damage and ratio, then publish its timestamps. */
void func_L15_004D8970(void *arg0, f32 amount) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0xAC);
    if ((s32)((u32)D_0021DE40 - 4500U) < *(s32 *)(p + 0x240)) return;
    if ((s32)((u32)D_0021DE40 - 750U) < *(s32 *)(p + 0x21C)) return;
    if (D_0024798C[0]) return;
    if (amount > 50.0f) {
        *(s32 *)(p+0x218) = func_L15_004D8480(p+0x244, 3, 0x2B10, 0x2B11, 0x2B12);
    } else if (*(f32 *)(p+0x50)/(f32)*(s32 *)(p+0x54) < 0.1f) {
        *(s32 *)(p+0x218) = func_L15_004D8480(p+0x244, 2, 0x2B13, 0x2B14);
    } else {
        *(s32 *)(p+0x218) = func_L15_004D8480(p+0x244, 7, 0x2B1C, 0x2B1D, 0x2B1E, 0x2B1F, 0x2B20, 0x2B21, 0x2B1B);
    }
    if (*(s32 *)(p+0x218) >= 0) {
        *(s32 *)(p+0x240) = D_0021DE40;
        *(s32 *)(p+0x21C) = D_0021DE40;
        func_0045DFC8(*(s16 *)(p+0x218),-1,2,0,0.75f,1.0f,0.0f,64.0f);
    }
}

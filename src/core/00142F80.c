/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 D_001956D8[];
extern void func_001428A0(void *state, void *block, s32 index);
extern void func_00142B60(void *s, void *a1, void *a2, int n);
extern s32 func_00146638();

/* Finishes a pending block: runs the pending step and updates the byte count. */
s32 func_00142F80(u8 *arg0)
{
    u8 *s;
    s32 ret;
    s32 a2;

    ret = 0;
    s = *(u8 **)(arg0 + 0x40);
    if (*(s32 *)(s + 0x4) != 0) {
        if (*(s32 *)(s + 0x8) != 0) {
            a2 = *(s32 *)(s + 0x128);
            if (*(s32 *)(s + 0x130) != 0) {
                func_00146638(s, (s32)D_001956D8, a2);
            } else if (*(s32 *)(s + 0x184) == 3) {
                func_001428A0(s, *(void **)(s + 0x1CC), a2 - 1);
            } else {
                func_00142B60(s, *(void **)(s + 0x1DC), *(void **)(s + 0x1EC), a2 - 1);
            }
            ret = 1;
            *(s32 *)(s + 0x130) = 0;
            *(s32 *)(arg0 + 0x8) = *(s32 *)(s + 0x128) - *(s32 *)(s + 0xC0);
            *(s32 *)(s + 0x4) = 0;
        }
    }
    return ret;
}

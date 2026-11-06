/* cflags: -ffast-math */
#include "common.h"

extern f32 D_0021DE74;
extern f32 D_0021DE7C;
extern s32 func_00490330(s32, s32, s32, s32);
extern void func_0051CBE8(void *, f32, f32, f32, s32);
extern f32 func_00476678(void *, void *, f32, f32, f32, f32, s32);

void func_0051CCC0(u8 *a0, s32 a1, f32 a2, f32 a3, f32 a4)
{
    if (*(s32 *)(a0 + 0x25CC) != 0x3F && *(s32 *)(a0 + 0x1AE0) != 0) {
        f32 clamp1;
        f32 clamp0;

        if (a0[0x265A] == 0) {
            if (func_00490330(0x28, 2, 0, *(s32 *)(a0 + 0x2F00)) == 0) {
                goto clamped;
            }
        }
        if (*(s32 *)(a0 + 0x2318) != 1) {
            clamp1 = D_0021DE74 * 0.2f;
            clamp0 = D_0021DE7C * 52.35987854003906f;
            clamp1 *= *(f32 *)(a0 + 0x25C4);
            clamp0 *= *(f32 *)(a0 + 0x25C4);
            a2 = a2 < clamp1 ? clamp1 : a2;
            a4 = a4 < clamp0 ? clamp0 : a4;
        }
    }

clamped:
    if (a0[0x2659] != 0) {
        func_0051CBE8(a0, a2, a3, a4, a1);
    } else {
        *(f32 *)(a0 + 0x17A8) = func_00476678(a0 + 0xB8, a0 + 0x17A4,
                                               *(f32 *)(a0 + 0x17A0), a2, a3, a4, a1);
    }
}

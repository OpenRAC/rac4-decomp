#include "common.h"

extern void func_L00_007107F0(void *arg0, void *arg1);

// Init the base, set fields from arg1, then call the virtual method at +0xE8 with arg1 + 0x44.
void func_L00_00714E78(u8 *self, u8 *src) {
    s32 f;

    func_L00_007107F0(self, src);
    f = *(s32 *)(src + 0x40);
    *(u8 *)(self + 0x60) = 0;
    *(u32 *)(self + 0x130) = 0x80D6CBBE;
    *(s32 *)(self + 0x5C) = f;
    *(s32 *)(self + 0x12C) = 0;
    *(u8 *)(self + 0x134) = 0;
    (*(void (**)(u8 *, u8 *))(*(u8 **)(self + 0x58) + 0xE8))(self, src + 0x44);
}

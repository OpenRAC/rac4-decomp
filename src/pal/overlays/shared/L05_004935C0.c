/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern f32 func_00472EB8(f32, f32);
extern u8 D_00396BD0[];

void func_L05_004935C0(void *arg0, s32 arg1, s32 arg2)
{
    s32 index;
    u8 *slot;
    u8 *entry;
    u8 *state = *(u8 **)((u8 *)arg0 + 0xAC);

    entry = *(u8 **)(state + 0x264);
    if (entry != NULL) {
scan:
        if (*(s32 *)(entry + 4) != arg1 || *(s32 *)entry != arg2) {
            entry = *(u8 **)(entry + 8);
            if (entry == NULL) {
                goto allocate;
            }
            goto scan;
        }
    } else {
allocate:
        for (index = 0, slot = D_00396BD0; index < 100; index++, slot += 0x20) {
            if (*(s32 *)slot == 0) {
                *(u8 **)(slot + 8) = *(u8 **)(state + 0x264);
                *(u8 **)(state + 0x264) = slot;
                *(s32 *)slot = arg1;
                *(s32 *)(slot + 4) = arg2;
                *(s32 *)(slot + 0xC) = 0;
                *(f32 *)(slot + 0x10) = func_00472EB8(0.0f, 1.0f);
                *(f32 *)(slot + 0x14) = func_00472EB8(0.0f, 1.0f);
                return;
            }
        }
    }
}

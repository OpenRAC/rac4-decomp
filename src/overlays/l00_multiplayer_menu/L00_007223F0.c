#include "common.h"

extern s32 func_L00_005C9F50(s32);
void func_L00_00769DE0(void *);
extern void *D_002233A4;

/* Update the menu state at arg0 from the table at D_002233A4+0x3C: refresh the cached entry and send the matching selection calls. */
void func_L00_007223F0(u8 *arg0) {
    u8 *s0;
    u8 *s2;
    u8 *temp_a0;
    u8 *temp_a1;
    u8 *temp_s0;
    u8 *temp_s0_2;
    u8 *temp_s0_3;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;

    s0 = 0;
    s2 = *(u8 **)((u8 *)D_002233A4 + 0x3C);
    if (*(u8 *)(s2 + 0x408) != 0) {
        temp_v1 = *(s32 *)(s2 + 0x40C);
        if (temp_v1 >= 0) {
            s0 = s2 + ((temp_v1 * 0xC) + 0x420);
        }
    }
    if (*(u8 *)(arg0 + 0x264) != 0 && *(u8 *)(s2 + 0x410) == 0) {
        *(s32 *)(arg0 + 0x260) = *(s32 *)(s2 + 0x418);
        func_L00_00769DE0(s2);
        *(u8 *)(arg0 + 0x264) = 0;
    }
    if (*(u8 *)(arg0 + 0x264) == 0) {
        temp_v1_2 = *(s32 *)(s2 + 0x418);
        if (*(s32 *)(arg0 + 0x260) != temp_v1_2) {
            *(s32 *)(arg0 + 0x260) = temp_v1_2;
            temp_v0 = *(s32 *)(s0 + 4);
            *(s32 *)(arg0 + 0x268) = temp_v0;
            if (temp_v0 == 0) {
                temp_s0 = *(u8 **)(*(u8 **)(arg0 + 0xB8) + 0x58);
                ((void (*)(void *, s32))(*(s32 *)(temp_s0 + 0xE8)))(*(void **)(arg0 + 0xB8), func_L00_005C9F50(0x101E));
                temp_a0 = *(u8 **)(arg0 + 0xB8);
                ((void (*)(void *, s32, s32))(*(s32 *)(*(u8 **)(temp_a0 + 0x58) + 0x20)))(temp_a0, 3, 0);
                *(s32 *)(arg0 + 0x26C) = -1;
                if (*(u8 *)(s2 + 0x30) != 0) {
                    temp_s0_2 = *(u8 **)(*(u8 **)(arg0 + 0xC4) + 0x58);
                    ((void (*)(void *, s32))(*(s32 *)(temp_s0_2 + 0xE8)))(*(void **)(arg0 + 0xC4), func_L00_005C9F50(0xFD5));
                }
            } else {
                temp_a1 = *(u8 **)(*(u8 **)(s0 + 8));
                if (*(u8 *)(temp_a1 + 0xC8) != 0) {
                    *(s32 *)(arg0 + 0x26C) = *(s32 *)(temp_a1 + 0xCC);
                    *(s32 *)(arg0 + 0x270) = *(s32 *)(temp_a1 + 0xD0);
                } else {
                    *(s32 *)(arg0 + 0x26C) = -1;
                }
                temp_a0 = *(u8 **)(arg0 + 0xB8);
                ((void (*)(void *, void *))(*(s32 *)(*(u8 **)(temp_a0 + 0x58) + 0xE8)))(temp_a0, temp_a1);
                temp_a0 = *(u8 **)(arg0 + 0xB8);
                ((void (*)(void *, s32, s32))(*(s32 *)(*(u8 **)(temp_a0 + 0x58) + 0x20)))(temp_a0, 2, 0);
                if (*(u8 *)(s2 + 0x30) != 0) {
                    temp_s0_3 = *(u8 **)(*(u8 **)(arg0 + 0xC4) + 0x58);
                    ((void (*)(void *, s32))(*(s32 *)(temp_s0_3 + 0xE8)))(*(void **)(arg0 + 0xC4), func_L00_005C9F50(0xFD6));
                }
            }
        }
    }
}

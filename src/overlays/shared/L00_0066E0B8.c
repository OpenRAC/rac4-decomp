#include "common.h"

extern s32 D_1DFA70[];
extern s32 D_0032B0E0[];

// Copy the first word of D_1DFA70 into its 0x30 slot and clear the 0x34 slot,
// then clear the first two words of 64 entries of D_0032B0E0 (stride 0x10).
void func_L00_0066E0B8(void) {
    s32 value = D_1DFA70[0];
    u8 *p = (u8 *)D_0032B0E0;
    s32 i;

    *(s32 *)((u8 *)D_1DFA70 + 0x34) = 0;
    *(s32 *)((u8 *)D_1DFA70 + 0x30) = value;
    for (i = 0x3F; i >= 0; i--) {
        *(s32 *)(p + 0x0) = 0;
        *(s32 *)(p + 0x4) = 0;
        p += 0x10;
    }
}

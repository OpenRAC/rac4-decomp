#include "common.h"

extern u8 *D_222990;

// Store the slot value and mark the matching object busy.
void func_L01_00524170(u8 *arg0, s32 arg1) {
    u8 *rec = *(u8 **)(arg0 + 0x70);
    s32 obj = *(s32 *)(D_222990 + *(s16 *)(arg0 + 0x84) * 0x20 + 0x1C);

    *(s16 *)(rec + 0x54) = arg1;
    *(s32 *)(obj + 0x108) = 1;
}

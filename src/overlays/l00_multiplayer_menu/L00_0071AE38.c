#include "common.h"

extern void func_0011AFC8(void *, s32, s32);

// Fill a message record: kind 0xA, two words at +4 and +8, an optional
// 0x33-byte text at +0xC (empty when null), a word at +0x40 and an optional
// 0xC7-byte text at +0x44.
void func_L00_0071AE38(void *record, u32 param_a, s32 param_b, s32 text_a, s32 param_c, s32 text_b) {
    *(s32 *)((u8 *)record + 4) = param_a;
    *(s32 *)((u8 *)record + 8) = param_b;
    if (text_a != 0) {
        func_0011AFC8((u8 *)record + 0xC, text_a, 0x33);
        *((u8 *)record + 0x3F) = 0;
    } else *((u8 *)record + 0xC) = 0;
    *(s32 *)((u8 *)record + 0x40) = param_c;
    *(s32 *)record = 0xA;
    if (text_b != 0) {
        func_0011AFC8((u8 *)record + 0x44, text_b, 0xC7);
        *((u8 *)record + 0x10B) = 0;
    } else *((u8 *)record + 0x44) = 0;
}

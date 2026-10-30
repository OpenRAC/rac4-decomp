#include "common.h"

extern void func_004A1310(void *arg0);

// Stores arg1 at offset 0x44 of arg0, then calls it with the word at 0x54 if that word is not negative; if it returns zero, calls func_004A1310.
void func_004A11F0(void *arg0, s32 (*arg1)(s32)) {
    s32 temp_a0;

    *(s32 (**)(s32))((u8 *)arg0 + 0x44) = arg1;
    temp_a0 = *(s32 *)((u8 *)arg0 + 0x54);
    if ((temp_a0 >= 0) && (arg1 != NULL) && (arg1(temp_a0) == 0)) {
        func_004A1310(arg0);
    }
}

#include "common.h"

extern s32 func_0011A9EC(void *, void *);
extern s32 func_0011AB04(u8 *);
extern void func_L00_007162A0(void *);

// Appends the string arg1 to the buffer at +0xB7C if it fits below 0x400 bytes, then updates the object.
void func_L00_00715870(u8 *arg0, u8 *arg1) {
    s32 len = func_0011AB04(arg1);
    s32 pos = *(s32 *)(arg0 + 0xF7C);

    if (len + pos < 0x400) {
        *(s32 *)(arg0 + 0xB78) = 0;
        func_0011A9EC(arg0 + (pos + 0xB7C), arg1);
        *(s32 *)(arg0 + 0xF7C) = *(s32 *)(arg0 + 0xF7C) + len;
        func_L00_007162A0(arg0);
    }
}

#include "common.h"

extern s32 func_0011AB04(u8 *);
extern char *func_0011AFC8(char *, char *, s32);
extern void func_L00_007162A0(void *);

// Set or clear the object's text buffer and refresh it.
void func_L00_00716790(u8 *arg0, char *arg1) {
    u8 *temp;

    *(s32 *)(arg0 + 0xB78) = 0;
    if (arg1 == 0) {
        arg0[0xB7C] = 0;
        *(s32 *)(arg0 + 0xF7C) = 0;
    } else {
        temp = arg0 + 0xB7C;
        func_0011AFC8((char *)temp, arg1, 0x400);
        arg0[0xF7B] = 0;
        *(s32 *)(arg0 + 0xF7C) = func_0011AB04(temp);
        func_L00_007162A0(arg0);
    }
}

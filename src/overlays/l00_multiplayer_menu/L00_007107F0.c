#include "common.h"

extern char *func_0011AFC8(char *, char *, s32);
void func_L00_007107F0(void *arg0, void *arg1) {
    char *a0 = (char *)arg0; char *a1 = (char *)arg1;
    *(s32 *)(a0 + 0x0) = *(s32 *)(a1 + 0x0);
    *(s32 *)(a0 + 0xC) = 0;
    *(s32 *)(a0 + 0x10) = *(s32 *)(a1 + 0x4);
    *(s32 *)(a0 + 0x14) = *(s32 *)(a1 + 0x8);
    func_0011AFC8(a0 + 0x18, a1 + 0xC, 0x33);
    *(s8 *)(a0 + 0x4B) = 0;
    *(s32 *)(a0 + 0x50) = 0;
    *(s32 *)(a0 + 0x4C) = 0;
}

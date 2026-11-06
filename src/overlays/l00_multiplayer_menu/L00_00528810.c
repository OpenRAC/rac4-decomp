/* cflags: @ee29 -O2 -G0 */
#include "common.h"
s32 func_138290(void *);
s32 func_L00_005288B8(u8 *);
s32 func_L00_005288D8(s32, s32, s32);
s32 func_L00_00528948(s32 *);
s32 func_L00_00528810(void) {
    u8 stack[0x30];
    s32 temp_v0;
    temp_v0 = func_138290(stack);
    if (temp_v0 == 0 || stack[0] != 0) return -1;
    *(s32 *)(stack + 0x24) = func_L00_005288B8(stack + 7) + 0x64;
    *(s32 *)(stack + 0x20) = func_L00_005288B8(stack + 6) - 1;
    *(s32 *)(stack + 0x1C) = func_L00_005288B8(stack + 5);
    *(s32 *)(stack + 0x18) = func_L00_005288B8(stack + 3);
    *(s32 *)(stack + 0x14) = func_L00_005288B8(stack + 2);
    *(s32 *)(stack + 0x10) = func_L00_005288B8(stack + 1);
    *(s32 *)(stack + 0x28) = func_L00_005288D8(*(s32 *)(stack + 0x24) + 0x76C, *(s32 *)(stack + 0x20), *(s32 *)(stack + 0x1C));
    return func_L00_00528948((s32 *)(stack + 0x10));
}

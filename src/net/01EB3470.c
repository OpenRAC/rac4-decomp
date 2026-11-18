/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_0011A518(void *, s32, s32);
extern s32 func_01EA8F98(s32 *arg0);
extern s32 func_01EA90F0(s32);
extern s32 func_01EA94D0(s32 *out, s64 id);

// Sets up the two 0x40-byte buffers of a context from arg1 and arg1 + 0x40, or clears them
s32 func_01EB3470(s32 arg0, s32 arg1) {
    s32 ctx;
    s32 temp_a0;
    s32 temp_a0_2;

    ctx = func_01EA90F0(arg0);
    if (ctx == 0) {
        return -1;
    }
    if (func_01EA8F98((s32 *)arg1) != 0 || func_01EA8F98((s32 *)(arg1 + 0x40)) != 0) {
        temp_a0 = *(s32 *)(ctx + 0x1C);
        if (temp_a0 != 0) {
            func_0011A518((void *)temp_a0, 0, 0x40);
        }
        temp_a0_2 = *(s32 *)(ctx + 0x20);
        if (temp_a0_2 != 0) {
            func_0011A518((void *)temp_a0_2, 0, 0x40);
        }
        return 0;
    }
    if (*(s32 *)(ctx + 0x1C) == 0) {
        func_01EA94D0((s32 *)(ctx + 0x1C), 0x40);
    }
    if (*(s32 *)(ctx + 0x20) == 0) {
        func_01EA94D0((s32 *)(ctx + 0x20), 0x40);
    }
    func_0011A370(*(u8 **)(ctx + 0x1C), (u8 *)arg1, 0x40);
    func_0011A370(*(u8 **)(ctx + 0x20), (u8 *)(arg1 + 0x40), 0x40);
    return 0;
}

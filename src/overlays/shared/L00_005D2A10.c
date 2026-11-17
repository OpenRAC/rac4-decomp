#include "common.h"

extern void func_L00_005BCAE0(void *, s32, s32);
extern void func_L00_005BCBF0(void *, void *, s32);
extern void func_L00_0066D6E8(void *a0);
extern s32 D_1D2200[];

/* Sets up the block at D_1D2200 from the header at arg0 and runs each entry through the copy and fixup calls */
void func_L00_005D2A10(s32 *arg0, s32 *arg1) {
    s32 n;
    s32 i;
    u8 *ptr;
    u8 *src;

    src = (u8 *)arg0 + 0x10;
    n = arg0[0];
    D_1D2200[0xAC] = n;
    if (n != 0) {
        D_1D2200[0xAD] = *arg1;
        *arg1 = (*arg1 + n * 0x90 + 0x3F) & 0xFFFFFFC0;
        func_L00_005BCAE0((void *)D_1D2200[0xAD], 0, D_1D2200[0xAC] * 0x90);
        for (i = 0; i < D_1D2200[0xAC]; i++) {
            ptr = (u8 *)D_1D2200[0xAD] + i * 0x90;
            func_L00_005BCBF0(ptr, src, 0x90);
            func_L00_0066D6E8(ptr);
            src += 0x90;
        }
    } else {
        D_1D2200[0xAD] = 0;
    }
}

#include "common.h"

extern void func_0070C990(void *, void *);
extern s32 D_1725F0[];
extern s32 *D_0021DFE8;

/* collects the valid entries of a ten-slot table into the menu state */
void func_L00_0072EED0(s32 *arg0) {
    s32 i;
    s32 v;
    s32 n;

    *(u8 *)((u8 *)arg0 + 0x2A0) = 1;
    func_0070C990((u8 *)arg0 + 0x2A4, D_1725F0);
    arg0[0x708 / 4] = 0;
    if (D_0021DFE8 != 0) {
        i = 0;
        do {
            v = *(s32 *)((u8 *)D_0021DFE8 + (i << 2) + 0x174);
            i++;
            if (v != -1) {
                s32 *out = arg0 + 0x70C / 4;
                n = arg0[0x708 / 4];
                *(s32 *)((u8 *)out + (n << 2)) = v;
                arg0[0x708 / 4] = n + 1;
            }
        } while (i < 10);
    }
}

#include "common.h"

extern s32 func_0011D5D8(const char *fmt, ...);
extern void func_00126E20(s32);
extern s32 func_0012A718();
extern s32 func_0012A918(void *p);
extern void func_00158240(u8 *arg0, s32 arg1, s32 *arg2);
extern u8 D_001A47F0[];
extern u8 D_1BD480[];

s32 D_0021DCE8 = 0;
s32 D_0021DD20 = 0;
s32 D_0021DCC8[2] = {0, 0};
s32 D_0021DCE0[2] = {0, 0};
s32 D_0021DCD0[2] = {0, 0};

// Waits on the request slot at D_1BD480, then queues it and toggles which of the two slots is active.
void func_00158FF8(void) {
    s32 *a2;
    u8 *a0;

    a0 = (u8 *)D_0021DCE0[D_0021DCE8];
    a2 = (s32 *)D_0021DCC8[D_0021DCE8];
    func_00158240(a0, *a2, a2);
    while (func_0012A918(D_1BD480) != 0) {
        if (D_0021DD20 == 0) {
            func_0011D5D8(D_001A47F0);
        }
        func_00126E20(0);
    }
    func_0012A718(D_1BD480, 0x4D, 1, D_0021DCC8[D_0021DCE8], 0x1000 - D_0021DCD0[D_0021DCE8], D_0021DCE0[D_0021DCE8], *(s32 *)D_0021DCC8[D_0021DCE8] * 4 + 8, 0, 0);
    D_0021DCE8 = (D_0021DCE8 ^ 1) != 0;
    *(s32 *)D_0021DCC8[D_0021DCE8] = 0;
    D_0021DCD0[D_0021DCE8] = 0xFFC;
}

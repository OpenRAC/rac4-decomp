#include "common.h"

extern void func_005D7318();
extern u8 *func_006658C0(s32);
extern s32 func_L00_005A00F8(void);
extern void func_L00_0062F820();
extern void func_L00_0062F9A0();
extern void func_L00_006CB868(void *, s32);
extern s32 func_L00_006FF6D0(s32, s32);
extern s32 func_L00_006FF8E8(s32);
extern void func_L01_004AF358();
extern void func_L01_004AF530();
extern s32 D_0021DDB4;
extern s32 *D_0021DDA4;

// Per-player update: refresh each slot's state and handle changes.
void func_L01_004AF1F0(u8 *object) {
    u8 *linked = *(u8 **)(object + 0xAC);
    s32 i;
    s32 *p;

    if (object[0x20] == 0) func_L01_004AF358();
    if (linked[0x90] != 0) return;
    if (D_0021DDB4 == 2) return;
    if (func_L00_005A00F8() != 0) return;
    for (i = 0; i < *D_0021DDA4; i++) {
        s32 v;
        u8 *q;
        p = (s32 *)(linked + 0x88) + i;
        func_L00_0062F820(i);
        func_005D7318(i, 1);
        v = *p;
        q = func_006658C0(i);
        if (v != -1) {
            func_L00_0062F9A0(i, *p, 0);
            if (func_L00_006FF8E8(v) == 0) {
                if (func_L00_006FF6D0(*(s32 *)(q + 0x26E4), v) <= 0) {
                    func_L01_004AF530(object, i);
                }
            }
        } else if (*(s32 *)(q + 0x24B0) != 0) {
            *(s32 *)(q + 0x24B0) = 0;
            if (*(s32 *)(q + 0x2318) != 1) func_L00_006CB868(q, 1);
        }
    }
}

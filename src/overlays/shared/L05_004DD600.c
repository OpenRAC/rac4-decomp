#include "common.h"

extern void func_L00_005DD4A0(void *);
extern s32 func_L00_005E6058(void *, s32, s32);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern u8 *D_363038[];

// Clears the four flags and starts the next state, or refreshes each flag from whether its object passes the check.
void func_L05_004DD600(u8 *arg0)
{
    u8 *st = *(u8 **)(arg0 + 0xAC);
    u8 **q;
    u8 *o;
    u8 *f;
    u8 *z;
    s32 i;

    switch (arg0[0x20]) {
    case 0:
        i = 3;
        z = st + 7;
        for (; i >= 0; i--) {
            *z = 0;
            z--;
        }
        if (*(s32 *)st == -1) {
            func_L00_005DD4A0(arg0);
        } else {
            arg0[0x30] = 0xFF;
            func_L01_00591BD8(arg0, 1, -1);
        }
        break;
    case 1:
        i = 0;
        o = D_363038[0];
        q = D_363038;
        do {
            f = st + 4 + i;
            if (o != 0 && *(s32 *)(o + 0x25CC) != 0x31 && i < 4) {
                if (func_L00_005E6058(o + 0xA0, *(s32 *)st, 0) == 0) {
                    *f = 0;
                } else {
                    if (*f == 0) {
                        (*(void (**)(u8 *))(*(u8 **)(o + 0x14) + 0x38))(o);
                        (*(void (**)(u8 *, s32, s32, s32, s32))(*(u8 **)(o + 0x14) + 0x3C))(o, 0, 1, 0, 1);
                    }
                    *f = 1;
                }
            }
            q++;
            i++;
            o = *q;
        } while (i < 10);
        break;
    }
}

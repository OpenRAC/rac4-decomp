#include "common.h"

extern s32 D_357D68[];
extern s32 D_0021DDB8;
extern void func_L01_0063B1E8(s32 *, s32);

/* Defined in this file: retail reaches it through $gp outside a delay slot. */
s32 D_00221928 = 0;

void func_L01_0046EC68(s32 arg0) {
    s32 temp;

    temp = D_0021DDB8;
    if (temp + 3 < D_00221928) {
        D_00221928 = temp;
    }
    if (D_00221928 < temp) {
        D_00221928 = temp;
        func_L01_0063B1E8(D_357D68, arg0);
    }
}

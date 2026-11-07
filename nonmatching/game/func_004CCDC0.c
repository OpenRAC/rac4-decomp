/* Not matching yet: BYTES 11/176 (tools/try_func.py func_004CCDC0 --diff). Not part of the build. */
#include "common.h"

extern u8 func_0047D278(s32 arg0);
extern s32 func_004CCFD8(s32 i);
extern s32 D_0030EA50[];

s32 D_00221914 = 0;

s32 func_004CCDC0(s32 arg0)
{
    s32 v;

    if (arg0 < 8) {
        v = 4;
        if (func_0047D278(5) != 0) {
            v = 5;
        }
        if (D_00221914 == 0) {
            D_0030EA50[0] = 1;
            D_0030EA50[1] = 2;
            D_0030EA50[2] = 3;
            D_0030EA50[3] = v;
            D_0030EA50[4] = 6;
            D_0030EA50[5] = 7;
            D_0030EA50[6] = 8;
            D_0030EA50[7] = 9;
            D_00221914 = 1;
        }
        return D_0030EA50[arg0];
    }
    return func_004CCFD8(arg0);
}

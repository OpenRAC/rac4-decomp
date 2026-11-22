#include "common.h"

extern s32 *D_0021DDA4;
extern u8 *D_0021DFE8;
extern s32 D_00172170[];
extern s32 D_004B4A80[];

s32 func_L00_006A9220(s32 arg0) {
    s32 flag = 0;
    s32 idx;

    if (*D_0021DDA4 >= 2 || (D_0021DFE8 + arg0)[0x104] != D_00172170[0]) {
        flag = 1;
    }
    idx = (D_0021DFE8 + arg0)[0xF0];
    if (idx < 0) {
        idx = 0;
    }
    if (flag) {
        if (idx >= 20) {
            return D_004B4A80[idx] + 1;
        }
        return D_004B4A80[idx] + 100;
    }
    return D_004B4A80[idx];
}

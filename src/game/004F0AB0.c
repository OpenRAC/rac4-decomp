#include "common.h"

extern s32 func_0011D5D8(const char *, ...);
extern void func_00126E20(s32);
extern s32 func_00137FB0(void);
extern s32 func_001593C8(s32 arg0, s32 arg1, s32 arg2, void *arg3);
extern s32 func_00159488(s32 arg0);
s32 D_00220910 = 0;
extern char D_003D31E8[];
extern char D_003D3200[];

s32 func_004F0AB0(s32 *arg0, s32 arg1, s32 arg2) {
    u8 buf[4];
    s32 v;
    s32 ret;

    ret = 0;
    if (D_00220910 != 0) {
        func_00126E20(2);
        if (func_00159488(1) == 0) {
            D_00220910 = 0;
            if (func_00137FB0() == 0) {
                v = arg2 >> 11;
                ret = v << 11;
                arg0[2] += v;
            } else {
                func_0011D5D8(D_003D31E8);
            }
        }
        goto end;
    } else {
        buf[0] = 100;
        buf[1] = 0;
        buf[2] = 0;
        func_00159488(0);
        if (func_001593C8(arg0[2], arg2 >> 11, arg1, buf) != 0) {
            D_00220910 = 1;
        } else {
            func_0011D5D8(D_003D3200);
        }
        ret = 0;
    }
end:
    return ret;
}

#include "common.h"

extern s16 func_00547E00(u8 *a0, s32 a1);
extern void *func_00548D28(s32 arg0, s32 arg1);
extern s32 D_0021DFF0;
extern s32 D_0021EDD4;

// Returns 1 when the entry's field at 0x42 is clear, or the count test or the flag and object test passes.
s32 func_00547EC8(u8 *arg0, s32 arg1) {
    s32 flag;

    if (*(s16 *)((u8 *)func_00548D28(arg1, 0) + 0x42) == 0) {
        return 1;
    }
    flag = 0;
    if (func_00547E00(arg0, arg1) > 0 || (D_0021EDD4 == 1 && *(s8 *)((u8 *)D_0021DFF0 + 0x20) != 0)) {
        flag = 1;
    }
    return flag;
}

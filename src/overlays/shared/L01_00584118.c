#include "common.h"

extern s32 D_0021EBD8;
extern void *func_L01_00584068(s32);
extern s32 func_L00_005CF6B8(u8, s32);
extern s32 func_L01_006538A8(s32, s32);

s32 func_L01_00584118(s32 arg0) {
    void *temp;

    D_0021EBD8 = arg0;
    temp = func_L01_00584068(arg0);
    func_L00_005CF6B8(*(u8 *)((char *)temp + 0x18), 0);
    func_L01_006538A8(*(s32 *)temp, 0);
    return 1;
}

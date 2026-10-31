#include "common.h"

extern void func_00464038(s32 arg0);
extern void func_004F3468(void);
extern u32 D_1DFC40[];

void func_004F4F70(s32 arg0) {
    func_004F3468();
    D_1DFC40[5] = arg0;
    D_1DFC40[6] = 0;
    func_00464038(0);
}

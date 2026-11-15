#include "common.h"

extern float D_0021E8DC;
extern float D_00222B50;
extern void func_00449B28(s32 count, s32 flag);

void func_L01_00636C58(void) {
    D_0021E8DC = 1.2f;
    if (D_00222B50 < 1.0f) {
        func_00449B28(5, 1);
    }
}

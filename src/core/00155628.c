#include "common.h"

extern void func_00126C50(s32 *);
extern s32 func_00155580(void);
extern u8 D_0016FC1A[];

// Get value from buffer or global
u8 func_00155628(void) {
    u32 buf[4];

    if (func_00155580() == 0) {
        func_00126C50((s32 *)buf);
        return (buf[0] >> 1) & 3;
    }
    return D_0016FC1A[0];
}

#include "common.h"

extern s32 func_00501458(s32 *p, s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_004D49A8(void);
extern void func_004D4BA8(void);
extern void func_004D4C58(void);
extern u8 D_31B970[];
s32 D_002219F4 = 0;
// On first call register the block D_31B970 through func_00501458 with three callbacks, then return its address.
void *func_004D4710(void) {
    if (D_002219F4 == 0) {
        func_00501458((s32 *)D_31B970, (s32)func_004D49A8, (s32)func_004D4BA8, (s32)func_004D4C58, 0, 0);
        D_002219F4 = 1;
    }
    return D_31B970;
}

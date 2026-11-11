#include "common.h"

extern s32 func_004A8518(s32 arg0);
extern u8 D_003D17E0[];

/* Return the byte of table D_003D17E0 at the index func_004A8518 gives for 0x20. */
u8 func_004A85D0(f32 angle) {
    return *(func_004A8518(0x20) + D_003D17E0);
}

#include "common.h"

s32 func_00588670(s16, s32, s32);
typedef struct { u8 pad0[0xBC]; s16 fBC; } Type2;
typedef struct { u8 pad0[0x254]; Type2 *f320; } Type1;
typedef struct { u8 pad0[0xAC]; Type1 *fAC; } Type0;

// Look up the callback (func_00588670, table 8, 0x24 bytes) for the type of
// the +0x254 object of the linked +0xAC block; 0 when there is none.
s32 func_L01_004FA638(Type0 *object) {
    Type2 *target = object->fAC->f320;
    if (target == 0) return 0;
    return func_00588670(target->fBC, 8, 0x24);
}

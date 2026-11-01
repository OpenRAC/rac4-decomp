#include "common.h"

typedef struct {
    u8 pad00[0x16C];
    s32 flags16C;
} Record;

extern Record D_00308C80[];

s32 func_004ABFC0(s32 index)
{
    s32 result;

    if (~D_00308C80[index].flags16C < 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

#include "common.h"

typedef struct {
    u8 pad00[0x16C];
    s32 flags16C;
} Record;

extern Record D_00308B80[];

s32 func_004AB168(s32 index)
{
    s32 result;

    if (~D_00308B80[index].flags16C < 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

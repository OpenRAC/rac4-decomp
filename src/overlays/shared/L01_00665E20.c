#include "common.h"

typedef struct {
    s32 f00;
} Record;

extern Record D_002480C0[];

s32 func_L01_00665E20(s32 unused, s32 key)
{
    Record *record = D_002480C0;
    s32 i;

    for (i = 0; i < 256; i++, record++) {
        if (record->f00 == 0) {
            return i;
        }
    }
    return -1;
}

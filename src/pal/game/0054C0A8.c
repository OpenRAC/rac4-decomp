#include "common.h"

typedef struct {
    s32 f00;
    u8 pad04[0x2C];
} Record;

extern Record D_003E2F88[];

s32 func_0054C0A8(s32 unused, s32 key)
{
    Record *record = D_003E2F88;
    s32 i;

    for (i = 0; i < 189; i++, record++) {
        if (record->f00 == key) {
            return i;
        }
    }
    return 0;
}

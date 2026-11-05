#include "common.h"
typedef struct {
    u8 unknown0[0x14];
    s8 enabled;
    s8 mode;
} Record;
s32 func_0014DE80(const Record *record, s16 mode, f32 amount)
{
    s32 result = 0;
    if (record->enabled == 1 && mode == 1 && record->mode == 1 && 0.44999998807907104f <= amount) {
        result = 1;
    }
    return result;
}

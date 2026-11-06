#include "common.h"

typedef struct RecordPrefix {
    const u8 *object;
    u32 value;
} RecordPrefix;

extern const RecordPrefix *func_L00_006F4858(const u8 *object);

u32 func_L01_0058A760(const u8 *object)
{
    const RecordPrefix *record = func_L00_006F4858(object);
    if (record != NULL)
        return record->value;
    return 0;
}

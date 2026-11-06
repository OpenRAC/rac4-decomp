#include "common.h"
typedef struct {
    u8 prefix[9];
    u8 items[10];
    u8 rest[37];
} Record;
extern Record *func_0054B068(s32);
s32 func_0054B6F8(s32 id, s32 record)
{
    Record value = *func_0054B068(record);
    s32 i;
    for (i = 0; i < 10; i++)
        if (value.items[i] == id)
            return 1;
    return 0;
}

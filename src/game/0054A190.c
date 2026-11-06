#include "common.h"
typedef struct {
    u8 prefix[9];
    u8 items[10];
    u8 rest[37];
} Record;
extern Record *func_00549B00(s32);
s32 func_0054A190(s32 id, s32 record)
{
    Record value = *func_00549B00(record);
    s32 i;
    for (i = 0; i < 10; i++)
        if (value.items[i] == id)
            return 1;
    return 0;
}

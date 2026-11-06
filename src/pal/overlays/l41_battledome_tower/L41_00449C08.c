/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

void func_L41_00449C08(void *object, s32 value)
{
    void *record = *(void **)((u8 *)object + 0xAC);
    if (record != NULL)
        *(s32 *)((u8 *)record + 0x1C) = value;
}

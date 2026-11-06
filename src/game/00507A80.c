#include "common.h"

char D_00222114 = 0;

void *func_00507A80(void *table, u32 key)
{
    u8 *keys = (u8 *)table + 8;
    s32 i;
    u32 step;
    u32 size;
    void *deleted;
    table = (u8 *)table + 12;
    i = 0;
    size = 3;
    deleted = &D_00222114;
    step = 0;
    for (; i < 3; i++) {
        u32 offset = ((step + key % size) % size) << 3;
        void *value = *(void **)((u8 *)table + offset);
        if (value == NULL) {
            return NULL;
        }
        if (*(u32 *)(keys + offset) == key && value != deleted) {
            return value;
        }
        step += 0x13D573;
    }
    return NULL;
}

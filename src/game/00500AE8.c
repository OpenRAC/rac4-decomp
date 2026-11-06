#include "common.h"

extern char D_00222110;

void *func_00500AE8(void *table, u32 key)
{
    u8 *keys = (u8 *)table + 8;
    s32 i;
    u32 slot;
    void *deleted;

    table = (u8 *)table + 12;
    i = 0;
    deleted = &D_00222110;
    slot = key & 0x3FF;
    for (; i < 1024; i++) {
        u32 offset = (slot & 0x3FF) << 3;
        void *value = *(void **)((u8 *)table + offset);

        if (value == NULL) {
            return NULL;
        }
        if (*(u32 *)(keys + offset) == key && value != deleted) {
            return value;
        }
        slot += 0x13D573;
    }
    return NULL;
}

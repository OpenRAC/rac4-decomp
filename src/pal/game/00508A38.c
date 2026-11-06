#include "common.h"

char D_00222212 = 0;

void *func_00508A38(void *table, u32 key)
{
    u8 *keys = (u8 *)table + 8;
    s32 i;
    u32 slot;
    void *deleted;
    table = (u8 *)table + 12;
    i = 0;
    deleted = &D_00222212;
    slot = key & 7;
    for (; i < 8; i++) {
        u32 offset = (slot & 7) << 3;
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

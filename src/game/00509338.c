#include "common.h"
typedef s32 (*Callback)(void *, u32);
typedef struct {
    u32 key;
    Callback value;
} Entry;
typedef struct {
    s32 pad;
    s32 count;
    Entry entries[3];
} Table;
u8 D_0022211F = 0;
extern Callback func_00507F70(Table *, u32);
s32 func_00509338(Table *table, u32 key, Callback value)
{
    if (table->count < 3 && !func_00507F70(table, key)) {
        s32 attempts = 0;
        u32 size = 3;
        char *values = (char *)table + 12;
        Callback deleted = (Callback)&D_0022211F;
        char *keys = (char *)table + 8;
        u32 step = 0;
        for (; attempts < 3; attempts++, step += 0x13D573) {
            u32 offset = ((step + key % size) % size) * 8;
            Callback *slot = (Callback *)(values + offset);
            if (!*slot || *slot == deleted) {
                *slot = value;
                *(u32 *)(keys + offset) = key;
                table->count++;
                return 1;
            }
        }
    }
    return 0;
}

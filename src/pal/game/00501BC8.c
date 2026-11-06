#include "common.h"
typedef struct HashEntry {
    u32 key;
    void *value;
} HashEntry;
typedef struct Type1 {
    s32 f0, f4;
    HashEntry entries[1024];
} Type1;
extern void *func_00501B58(Type1 *, u32);
extern u8 D_00222210;
/* Insert a unique key into one of 1024 open-addressed slots. */
s32 func_00501BC8(Type1 *table, u32 key, void *value)
{
    if (table->f4 < 0x400) {
        if (func_00501B58(table, key))
            return 0;
        {
            s32 attempts = 0;
            char *values = (char *)table + 0xC;
            void *tombstone = (void *)&D_00222210;
            char *keys = (char *)table + 8;
            u32 probe = key & 0x3FF;
            do {
                s32 offset = (probe & 0x3FF) * 8;
                void **slot = (void **)(values + offset);
                void *current = *slot;
                if (!current || current == tombstone) {
                    *slot = value;
                    *(u32 *)(keys + offset) = key;
                    table->f4++;
                    return 1;
                }
                attempts++;
                probe += 0x13D573;
            } while (attempts < 0x400);
        }
    }
    return 0;
}

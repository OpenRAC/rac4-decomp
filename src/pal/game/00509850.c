#include "common.h"

typedef s32 (*Type2)(void *, f32 *);
typedef struct Type3 {
    u32 f0;
    Type2 f4;
} Type3;
typedef struct Type1 {
    s32 f0, f4;
    Type3 f8[8];
} Type1;
extern Type2 func_00508CF8(Type1 *, u32);
u8 D_00222218 = 0;

/* Insert a unique key into one of eight open-addressed slots. */
s32 func_00509850(Type1 *table, u32 key, Type2 value)
{
    if (table->f4 < 8) {
        if (func_00508CF8(table, key))
            return 0;
        {
            s32 attempts = 0;
            char *values = (char *)table + 0xC;
            Type2 tombstone = (Type2)&D_00222218;
            char *keys = (char *)table + 8;
            u32 probe = key & 7;
            do {
                s32 offset = (probe & 7) * 8;
                Type2 *slot = (Type2 *)(values + offset);
                Type2 current = *slot;
                if (!current || current == tombstone) {
                    *slot = value;
                    *(u32 *)(keys + offset) = key;
                    table->f4++;
                    return 1;
                }
                attempts++;
                probe += 0x13D573;
            } while (attempts < 8);
        }
    }
    return 0;
}

#include "common.h"

typedef struct {
    u8 unknown0[0xA4];
    s32 count;
} Collection;

typedef struct {
    u8 unknown0[0x10];
    u8 *entries[0];
} Entries;

void func_004526E0(void *unused, Collection *collection, const void *clearFirst, s32 value)
{
    s32 i;
    s32 j;
    u8 *entry;

    for (i = 0; i < collection->count; i++) {
        entry = ((Entries *)collection)->entries[i];
        if (clearFirst != 0) {
            for (j = 0; j < entry[0xA]; j++) {
                entry[9 + j * 0x40] = 0;
            }
        } else {
            entry[9] = value;
            for (j = 1; j < entry[0xA]; j++) {
                entry[9 + j * 0x40] = 0;
            }
        }
    }
}

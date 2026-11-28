#include "common.h"

typedef struct {
    u8 pad00[0x10];
    s32 key;
    u8 pad14[0xC];
} Entry;

extern s32 D_L05_00222AF8;
extern Entry *D_L05_00222AF4;

Entry *func_L05_004F4EB0(s32 key)
{
    s32 i = 0;
    if (i < D_L05_00222AF8) {
        Entry *entry = D_L05_00222AF4;
        do {
            if (entry->key == key)
                return entry;
            entry++;
        } while (++i < D_L05_00222AF8);
    }
    return NULL;
}

#include "common.h"

typedef struct { u8 pad0[0xF]; u8 count; u8 pad10[0xC]; u8 *entries; } Root;
typedef struct { s32 value; u8 pad4[0x1C]; s32 value2; u8 pad24[0xF]; u8 index; u8 pad34[0x1C]; } Entry;
extern Root *D_0032C400[];
extern s16 D_00331300[];
extern s32 D_00331900[];
/* Apply per-index override bits from a table to each listed root's entries. */
void func_L00_006702E0(void) {
    s32 *p;
    for (p = D_00331900; *p >= 0; p++) {
        Root *root = D_0032C400[*p];
        Entry *entry = (Entry *)root->entries;
        s32 i;
        for (i = 0; i < root->count; i++) {
            s16 *t = &D_00331300[entry->index * 2];
            if (t[0] != 0) entry->value = (entry->value & 0xFFFFC000) | t[0];
            if (t[1] != 0) entry->value2 = (entry->value2 & 0xFFFFC000) | t[1];
            entry++;
        }
    }
}

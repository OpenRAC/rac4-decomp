/* cflags: -mno-split-addresses */
#include "common.h"

typedef struct {
    s32 key;
    s32 val;
} Type1;

typedef struct {
    s32 f0;
    s32 count;
    Type1 entries[1024];
} Type2;

s32 func_00500AE8();
extern s32 D_222110[];

/* Inserts key/val into an open-addressed hash table (empty or tombstone slots); returns 1 on insert. */
s32 func_00500B58(Type2 *tbl, s32 key, s32 val)
{
    s32 i;
    s32 idx;
    s32 v;

    if (tbl->count >= 0x400) {
        return 0;
    }
    if (func_00500AE8() != 0) {
        return 0;
    }
    for (i = 0; i < 0x400; i++) {
        idx = ((key & 0x3FF) + i * 0x13D573) & 0x3FF;
        v = tbl->entries[idx].val;
        if (v == 0 || v == (s32)D_222110) {
            tbl->entries[idx].val = val;
            tbl->entries[idx].key = key;
            tbl->count++;
            return 1;
        }
    }
    return 0;
}

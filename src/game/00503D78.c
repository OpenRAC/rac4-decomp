#include "common.h"
typedef struct {
    s32 a, b, c;
} Entry;
typedef struct {
    s32 index;
    s32 pad;
    s32 count;
    s32 padC;
    Entry entries[64];
} Ring;
extern s32 func_00503E18(Ring *);
s32 func_00503D78(Ring *p, Entry *entry)
{
    if (p->count == 64)
        func_00503E18(p);
    p->entries[p->index] = *entry;
    p->index = (p->index + 1) % 64;
    p->count++;
    return 1;
}

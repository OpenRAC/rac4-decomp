/* cflags: -O2 -G8 -Wuninitialized -ffunction-sections */
#include "common.h"
#include "pal/word_probe3.h"

typedef struct {
    u32 key;
    void *value;
} Entry;

typedef struct {
    s32 f0;
    s32 count;
    Entry entries[3];
} Table;

char D_00222216 = 0;

void *func_00508C08(void *table, u32 key)
{
    PAL_WORD_PROBE3_LOOKUP(void *, table, key, D_00222216);
}

s32 func_0050AD58(Table *table, u32 key, void *value)
{
    PAL_WORD_PROBE3_INSERT(void *, table, key, value, D_00222216, func_00508C08);
}

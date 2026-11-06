/* cflags: -O2 -G8 -fopt-stack -ffunction-sections -Wuninitialized */
#include "common.h"
#include "pal/word_probe3.h"

typedef struct Object Object;
typedef s32 (*Callback)(Object *, u32);

char D_00223497 = 0;

Callback func_L00_006A3C40(void *table, u32 key)
{
    PAL_WORD_PROBE3_LOOKUP(Callback, table, key, D_00223497);
}



typedef struct {
    u32 key;
    Callback value;
} Entry;
typedef struct {
    s32 pad;
    s32 count;
    Entry entries[3];
} Table;

s32 func_L00_006A5008(Table *table, u32 key, Callback value)
{
    PAL_WORD_PROBE3_INSERT(Callback, table, key, value, D_00223497, func_L00_006A3C40);
}

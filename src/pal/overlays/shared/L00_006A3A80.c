/* cflags: -O2 -G8 -Wuninitialized -ffunction-sections */
#include "pal/word_insert.h"

/* Address-only marker; its checked initial byte is zero. */
u8 D_00223493 = 0;

s32 func_L00_006A3A80(void *table, s32 key)
{
    return pal_word_probe(table, key, (s32) &D_00223493);
}

s32 func_L00_006A4C98(void *table, s32 key, s32 new_value)
{
    PAL_WORD_INSERT_RETURN(table, key, new_value, D_00223493, func_L00_006A3A80)
}

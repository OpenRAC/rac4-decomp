/* cflags: -O2 -G8 -Wuninitialized */
#include "pal/word_probe.h"

/* Address-only marker; its initial byte is zero in the checked PAL image. */
u8 D_0022348B = 0;

s32 func_L00_006A36E0(void *table, s32 key)
{
    return pal_word_probe(table, key, (s32) &D_0022348B);
}

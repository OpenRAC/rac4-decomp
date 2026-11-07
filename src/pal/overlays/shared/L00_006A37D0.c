/* cflags: -O2 -G8 -Wuninitialized -ffunction-sections */
#include "pal/word_insert.h"

/* Address-only marker; its checked initial byte is zero. */
u8 D_0022348D = 0;

/* func_L00_006A37D0 is src/overlays/shared/L00_0069FFF0.c's func_L00_0069FFF0 on PAL. */
s32 func_L00_006A37D0(void *table, s32 key);

s32 func_L00_006A4598(void *table, s32 key, s32 new_value)
{
    PAL_WORD_INSERT_RETURN(table, key, new_value, D_0022348D, func_L00_006A37D0)
}

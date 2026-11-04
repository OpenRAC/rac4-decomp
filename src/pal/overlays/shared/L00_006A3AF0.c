/* cflags: -O2 -G8 -Wuninitialized -ffunction-sections */
#include "pal/word_probe.h"

/* Address-only marker; its initial byte is zero in the checked PAL image. */
u8 D_00223494 = 0;

s32 func_L00_006A3AF0(void *table, s32 key)
{
    return pal_word_probe(table, key, (s32) &D_00223494);
}

s32 func_L00_006A4EF8(void *table, s32 key, s32 new_value)
{
    s32 position;
    s32 count;
    s32 value;
    s32 offset;
    u8 *values;
    u8 *keys;
    s32 marker_address;
    if (*((s32 *) ((u8 *) table + 4)) >= 8 || func_L00_006A3AF0(table, key) != 0)
    {
        return 0;
    }
    count = 0;
    values = ((u8 *) table) + 12;
    marker_address = (s32) (&D_00223494);
    keys = ((u8 *) table) + 8;
    position = key & 7;
    do
    {
        offset = (position & 7) * 8;
        value = *((s32 *) (values + offset));
        if (value == 0 || value == marker_address)
        {
            *((s32 *) (values + offset)) = new_value;
            *((s32 *) (keys + offset)) = key;
            *((s32 *) ((u8 *) table + 4)) += 1;
            return 1;
        }
        count += 1;
        position += 1299827;
    }
    while (count < 8);
    return 0;
}

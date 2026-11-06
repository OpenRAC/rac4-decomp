#ifndef PAL_WORD_INSERT_H
#define PAL_WORD_INSERT_H

#include "pal/word_probe.h"

/* Return from a word-table insertion caller. Pass parameter names plus direct
 * lookup/marker identifiers. Keeping these identifiers visible preserves this
 * compiler's original direct-call scheduling and small-data classification. */
#define PAL_WORD_INSERT_RETURN(table_, key_, new_value_, marker_, lookup_) { \
    s32 position; \
    s32 count; \
    s32 value; \
    s32 offset; \
    u8 *values; \
    u8 *keys; \
    s32 marker_address; \
    if (*((s32 *) ((u8 *) table_ + 4)) >= 8 || lookup_(table_, key_) != 0) \
    { \
        return 0; \
    } \
    count = 0; \
    values = ((u8 *) table_) + 12; \
    marker_address = (s32) (&marker_); \
    keys = ((u8 *) table_) + 8; \
    position = key_ & 7; \
    do \
    { \
        offset = (position & 7) * 8; \
        value = *((s32 *) (values + offset)); \
        if (value == 0 || value == marker_address) \
        { \
            *((s32 *) (values + offset)) = new_value_; \
            *((s32 *) (keys + offset)) = key_; \
            *((s32 *) ((u8 *) table_ + 4)) += 1; \
            return 1; \
        } \
        count += 1; \
        position += 1299827; \
    } \
    while (count < 8); \
    return 0; \
}

#endif

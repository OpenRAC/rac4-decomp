#ifndef PAL_WORD_PROBE3_H
#define PAL_WORD_PROBE3_H

/* Each slot is a 32-bit key followed by a 32-bit stored value. The marker
 * is an address-only tombstone, and the three-slot table uses a fixed step. */
#define PAL_WORD_PROBE3_LOOKUP(TYPE, TABLE, KEY, MARKER) \
    u8 *keys = (u8 *)(TABLE) + 8; \
    s32 i; \
    u32 step; \
    u32 size; \
    TYPE deleted; \
    (TABLE) = (u8 *)(TABLE) + 12; \
    i = 0; \
    size = 3; \
    deleted = (TYPE)&(MARKER); \
    step = 0; \
    for (; i < 3; i++) { \
        u32 offset = ((step + (KEY) % size) % size) << 3; \
        TYPE value = *(TYPE *)((u8 *)(TABLE) + offset); \
        if (value == NULL) return NULL; \
        if (*(u32 *)(keys + offset) == (KEY) && value != deleted) return value; \
        step += 0x13D573; \
    } \
    return NULL

#define PAL_WORD_PROBE3_INSERT(TYPE, TABLE, KEY, VALUE, MARKER, LOOKUP) \
    if ((TABLE)->count < 3 && !LOOKUP((TABLE), (KEY))) { \
        s32 attempts = 0; \
        u32 size = 3; \
        char *values = (char *)(TABLE) + 12; \
        TYPE deleted = (TYPE)&(MARKER); \
        char *keys = (char *)(TABLE) + 8; \
        u32 step = 0; \
        for (; attempts < 3; attempts++, step += 0x13D573) { \
            u32 offset = ((step + (KEY) % size) % size) * 8; \
            TYPE *slot = (TYPE *)(values + offset); \
            if (!*slot || *slot == deleted) { \
                *slot = (VALUE); \
                *(u32 *)(keys + offset) = (KEY); \
                (TABLE)->count++; \
                return 1; \
            } \
        } \
    } \
    return 0

#endif

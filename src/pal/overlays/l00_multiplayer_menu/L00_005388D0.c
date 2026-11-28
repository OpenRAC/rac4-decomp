/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

typedef struct {
    u64 *words;
    s32 count;
    s32 capacity;
    s32 negative;
    s32 flags;
} PalBigInteger;

extern PalBigInteger *func_L00_005387C8(PalBigInteger *, s32);
extern void *func_0011A370(void *, const void *, u32);

/* Copy the limbs and sign into an existing integer, growing it as needed. */
PalBigInteger *func_L00_005388D0(PalBigInteger *destination, const PalBigInteger *source) {
    if (destination == source) {
        return destination;
    }
    /* Distinct inputs must point to live integers. */
    if (source->count > destination->capacity) {
        if (func_L00_005387C8(destination, source->count) == 0) {
            return 0;
        }
    } else if (destination == 0) {
        return 0;
    }

    func_0011A370(destination->words, source->words, source->count * sizeof(*source->words));
    destination->count = source->count;
    if (destination->count == 0 && destination->words != 0) {
        destination->words[0] = 0;
    }
    destination->negative = source->negative;
    return destination;
}

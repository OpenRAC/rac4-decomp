#include "common.h"

typedef struct Streams {
    f32 first[8];
    f32 second[8];
    f32 third[8];
    f32 fourth[8];
    u16 ids[8];
    u8 mode;
    u8 count;
} Streams;

s32 func_L01_00572330(Streams *destination, const Streams *source)
{
    s32 i;
    if (!destination || !source)
        return 1;
    for (i = 0; i < 8; i++) {
        destination->first[i] = source->first[i];
        destination->second[i] = source->second[i];
        destination->third[i] = source->third[i];
        destination->fourth[i] = source->fourth[i];
        destination->ids[i] = source->ids[i];
    }
    destination->count = source->count;
    destination->mode = source->mode;
    return 1;
}

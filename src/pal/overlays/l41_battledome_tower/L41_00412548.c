/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
/* Map the five admitted values to their signed result, or return -1. */
s32 func_L41_00412548(s32 value)
{
    int result;
    switch (value) {
    case 5: result = 4246; break;
    case 3: result = 4231; break;
    case 4: result = 4233; break;
    case 7: result = 4234; break;
    case 6: result = 4248; break;
    default: result = -1; break;
    }
    return result;
}

/* cflags: -ffast-math */
#include "common.h"

typedef struct {
    u8 pad00[0x20];
    f32 value;
} Entry;

extern Entry *func_0048A970(s64 handle);

s32 func_0048A368(void *unused, s64 handle, f32 value)
{
    s32 result = 0;
    Entry *entry = func_0048A970(handle);

    if (entry != NULL) {
        entry->value = value > 1.0f ? 1.0f : value;
        result = 1;
    }
    return result;
}

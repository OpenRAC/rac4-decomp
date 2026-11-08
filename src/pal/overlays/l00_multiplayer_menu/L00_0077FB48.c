/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern s32 D_004EF078[];

/* Read a table entry only when the unsigned index is in range. */
s32 func_L00_0077FB48(u32 index)
{
    if (index < 9) {
        return D_004EF078[index];
    }
    return 0;
}

/* cflags: -O1 -G8 -Wuninitialized */
#include "common.h"

extern u8 func_00483D30(void *object);

/* Query the linked object's byte unless this state is in the excluded range. */
s32 func_L01_003D7190(void *object)
{
    if ((u32)(*(u8 *)((u8 *)object + 0x20) - 13) >= 3U) {
        func_00483D30(object);
    }
    return 0;
}

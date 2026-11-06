/* cflags: -fno-opt-stack */
#include "common.h"

extern s32 func_001511F0(void *object0, void *object1, void *object2,
                         const void *plane0, const void *plane1, const void *plane2,
                         u32 unused6, u32 unused7, u32 unused8);

s32 func_001511C8(void *object0, void *object1, void *object2, const void *plane0, const void *plane1, const void *plane2)
{
    return func_001511F0(object0, object1, object2, plane0, plane1, plane2,
                         0, 0, 0);
}

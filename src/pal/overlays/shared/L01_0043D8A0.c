/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern u8 *func_0046C1F0(s32, s32);
extern void func_0047C2F0(void *, void *);

/* Creates an object, optionally copies the source object, and enables it. */
u8 *func_L01_0043D8A0(void *source, s32 classId)
{
    u8 *object;
    u8 *result;

    object = func_0046C1F0(classId, 128);
    result = 0;
    if (object) {
        if (*(u32 *)(object + 0x24))
            func_0047C2F0(object, source);
        *(object + 0x31) = 1;
        return object;
    }
    return result;
}

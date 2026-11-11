#include "common.h"

void *func_L00_005DEBD0(s16 type, s32 arg1, s32 arg2);
void func_L00_0066CCE8(void *object, s32 arg);

s32 func_L01_00588B08(void *object)
{
    u8 *list;
    u8 *previous;
    s32 (*callback)(void *);

    list = func_L00_005DEBD0(
        *(s16 *)((u8 *)object + 0xBC),
        15,
        16
    );

    if (list == 0) {
        return 0;
    }

    callback = *(s32 (**)(void *))list;

    if (callback != 0) {
        if (callback(object) == 0) {
            return 0;
        }
    } else {
        u16 flags;

        *(s32 *)((u8 *)object + 0x98) = 0;

        flags = *(u16 *)((u8 *)object + 0x34);
        flags |= 0x41;
        flags &= 0xEFFF;
        *(u16 *)((u8 *)object + 0x34) = flags;

        func_L00_0066CCE8(object, 1);

        *(u16 *)((u8 *)object + 0x34) |= 2;
    }

    previous = *(u8 **)(list + 0xC);

    if (previous != 0) {
        *(void **)(previous + 0xB8) = object;
        *(void **)((u8 *)object + 0xB8) = 0;
        *(void **)(list + 0xC) = object;
    } else {
        *(void **)(list + 0x8) = object;
        *(void **)(list + 0xC) = object;
        *(void **)((u8 *)object + 0xB8) = 0;
    }

    return 1;
}

/* cflags: -O2 -G8 */
#include "common.h"

s32 func_L01_005D73D0(s32, s32);

// Calls the object's +0x4C table entry and forwards the result with size 16.
void func_L01_00514BD8(s32 unused0, s32 unused1, void *object)
{
    s32 (*callback)(void *);

    callback = *(s32 (**)(void *))((u8 *)*(void **)((u8 *)object + 0x14) + 0x4C);
    func_L01_005D73D0(callback(object), 16);
}

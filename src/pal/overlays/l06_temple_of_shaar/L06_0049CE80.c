/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern void *func_0046DD08(s32, s32, s32);
extern void func_00474368(void *, s32, s32);
extern s32 D_00222694;
typedef s32 (*Callback)(void *, void *, s32);
void func_L06_0049CE80(void *arg0)
{
    s32 index;
    u8 *record;
    s32 result = *(u8 *)((u8 *)arg0 + 0x20);
    if (result == 0) {
        index = **(s32 **)((u8 *)arg0 + 0xAC);
        if (index != -1) {
            record = (u8 *)(D_00222694 + ((u32)index << 8));
            (*(Callback *)((u8 *)func_0046DD08(*(s16 *)(record + 0xBC), 0, 72) + 0x28))(record, arg0, 0);
        }
        func_00474368(arg0, 1, -1);
    }
    return;
}

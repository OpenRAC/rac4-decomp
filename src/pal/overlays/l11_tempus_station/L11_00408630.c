/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s32 func_0046C6B0(void *, void *);              /* extern */
extern s32 D_00222794;

void func_L11_00408630(void *arg0) {
    s32 temp_4;
    void *temp_2;

    temp_4 = *(*(s32 **)((u8 *)(arg0) + (0xAC)));
    if (temp_4 == -1) {
        func_0046C6B0(arg0, arg0);
        return;
    }
    temp_2 = D_00222794 + (temp_4 << 8);
    (*(u8 *)((u8 *)(arg0) + (0x20))) = (u8) (*(u8 *)((u8 *)(temp_2) + (0x20)));
    (*(s32 *)((u8 *)(arg0) + (0x60))) = (s32) (*(s32 *)((u8 *)(temp_2) + (0x60)));
}
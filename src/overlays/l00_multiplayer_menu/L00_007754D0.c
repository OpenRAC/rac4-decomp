#include "common.h"
void func_L00_007751E8(void *);                  /* extern */

void func_L00_007754D0(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 (*temp_v0)(s32, s32, s32);

    func_L00_007751E8(arg3);
    if (arg2 == 0) {
        (*(s32 *)((u8 *)(arg3) + 0)) = (s32) ((*(s32 *)((u8 *)(arg3) + 0)) | 0x102);
    }
    temp_v0 = (*(s32 (**)(s32, s32, s32))((u8 *)(arg3) + 0x18));
    if (temp_v0 != NULL) {
        temp_v0(arg2, (*(s32 *)((u8 *)(arg3) + 0xC)), (*(s32 *)((u8 *)(arg3) + 0x1C)));
    }
}

/* cflags: @ee29 */
#include "common.h"
s32 func_L00_00520378(void *, s32, s32, s32, s32, s32); /* extern */

void func_L00_005415E0(void *arg0, void *arg1, s32 arg2) {
    s32 var_a5;

    if (((*(s32 *)((u8 *)(arg1) + 0x14)) & 2) || (var_a5 = 0, ((arg2 & 2) != 0))) {
        var_a5 = 2;
    }
    func_L00_00520378(arg0, (*(s32 *)((u8 *)(arg1) + 0)), (*(s32 *)((u8 *)(arg1) + 4)), (*(s32 *)((u8 *)(arg1) + 0xC)), (*(s32 *)((u8 *)(arg1) + 0x10)), var_a5);
    (*(s32 *)((u8 *)(arg0) + 8)) = (s32) (*(s32 *)((u8 *)(arg1) + 8));
}

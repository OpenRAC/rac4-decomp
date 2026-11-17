/* cflags: @ee29 -O2 -G0 */
#include "common.h"
void func_L00_0053F170(s32, s32, u64, s32, void *, s32);
void func_L00_00519BB8(u8 *arg0, s32 arg1, s32 arg2, u32 arg3) {
    func_L00_0053F170(arg2, arg1, arg3, *(s32 *)(arg0 + 0x78),
                      arg0 + 0x2C, *(s32 *)(arg0 + 4));
}

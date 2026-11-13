/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern void func_L00_0053F930(void *input, void *output, long length,
                              s32 ks1, s32 ks2, s32 ks3, void *ivec, s32 enc);

void func_L00_00519B40(void *arg0, void *arg1, void *arg2, u32 arg3) {
    s32 ctx = *(s32 *)((u8 *)arg0 + 0x78);
    func_L00_0053F930(arg2, arg1, arg3, ctx, ctx + 0x180, ctx + 0x300,
                      (u8 *)arg0 + 0x2C, *(s32 *)((u8 *)arg0 + 4));
}

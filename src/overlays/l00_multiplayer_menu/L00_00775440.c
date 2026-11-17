#include "common.h"

extern s32 D_002233A4;
extern void func_007751C8(void *arg0);
extern s32 func_L00_00774F80(s32 arg0);
extern void func_L00_00775200(s32 *arg0, u8 *arg1);
extern s32 func_L00_0076CD18(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_L00_007754D0(s32 arg0, s32 arg1, s32 arg2, void *arg3);

// Look up the entry for arg0 through the global record; when func_L00_0076CD18 finds it, reset arg0 and return 1.
s32 func_L00_00775440(void *arg0) {
    u8 buf[0x80];
    s32 temp_s0;
    s32 var_s2;

    var_s2 = 0;
    temp_s0 = *(s32 *)((u8 *)D_002233A4 + 0x40);
    func_L00_00775200((s32 *)arg0, buf);
    if ((u32)func_L00_0076CD18(temp_s0, (s32)buf, *(s32 *)((u8 *)arg0 + 0x14), func_L00_00774F80(*(s32 *)((u8 *)arg0 + 0x14)), (s32)func_L00_007754D0, (s32)arg0) != 0xFFFFFFFF) {
        var_s2 = 1;
        func_007751C8(arg0);
    }
    return var_s2;
}

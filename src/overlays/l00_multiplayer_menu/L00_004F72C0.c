/* cflags: @ee29 -O2 -G0 */
#include "common.h"
extern u32 func_L00_004F72B0(void);
extern s32 func_L00_00516768(s32);
extern void func_L00_00516C28(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

s32 func_L00_004F72C0(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_L00_00516768(func_L00_004F72B0());
    if (temp_v0 == 0) {
        return 0;
    }
    func_L00_00516C28(temp_v0, 0x68, arg1, arg0);
    return temp_v0;
}

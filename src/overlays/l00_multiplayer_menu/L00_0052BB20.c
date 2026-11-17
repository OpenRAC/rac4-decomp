/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern void func_L00_005195A8(void *arg0, s32 arg1, s32 *arg2);
extern s32 func_L00_00540F30(s32 arg0, void *arg1);

// Looks up arg0's 0x128 entry with arg1 and, if found, returns the value func_L00_005195A8 reports for arg2.
s32 func_L00_0052BB20(u8 *arg0, void *arg1, s32 arg2) {
    s32 out[4];

    if (func_L00_00540F30(*(s32 *)(arg0 + 0x128), arg1) == 0) {
        return 0;
    }
    func_L00_005195A8(*(void **)(arg0 + 0x128), arg2, out);
    return out[0];
}

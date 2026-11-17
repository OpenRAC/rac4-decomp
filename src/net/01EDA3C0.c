/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 (*D_001995E8)(void *, s32);
extern void func_01EDA110(void *);
s32 func_01EDA3C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf[0x14];
    if (D_001995E8(buf, arg3) != 0) {
        return -1;
    }
    func_01EDA110(buf);
    return buf[11];
}

/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern s32 *func_00566230();
extern s64 func_005663E8(s32, s32, s32, s32);
extern void func_L00_004F7200(u8 *a0);
extern void func_L00_004F7228(void *arg0);
extern s32 func_L00_00506028(s32 arg0);

/* reads into a buffer through the object's handle, handling errors */
s32 func_L00_004F73A8(u8 *arg0, s32 arg1, s32 arg2) {
    s32 n = 0;

    if (arg1 != 0) {
        *func_00566230() = 0;
        n = func_005663E8(*(s32 *)(arg0 + 0x1C), arg1, arg2, 0);
        func_L00_004F7228(arg0);
        if (n <= 0 && func_L00_00506028(n) != 0) {
            func_L00_004F7200(arg0);
        }
    }
    return n;
}

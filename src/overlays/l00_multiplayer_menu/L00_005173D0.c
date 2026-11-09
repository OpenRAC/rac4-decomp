/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_004F8220(s32);
extern void func_L00_004F82B0(s32);
extern s32 func_L00_0052F7F0(s32, s32, s32);
extern void func_L00_0052FA40(s32);
extern s32 func_L00_0052FAA8(s32);

s32 func_L00_005173D0(s32 unused0, s32 *out, s32 arg2, s32 arg3) {
    s32 handle;
    s32 result;

    handle = func_L00_0052F7F0(0, arg2, arg3);
    if (handle == 0) {
        return 0;
    }
    result = func_L00_0052FAA8(handle);
    if (out != 0 && result != 0) {
        if (*out != 0) {
            func_004F8220(*out);
        }
        *out = result;
        func_L00_004F82B0(result);
    }
    func_L00_0052FA40(handle);
    return result;
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s64 func_L00_0051CD28(void *arg0, void *arg1);
extern s32 func_L00_0051CE60(s32);
extern s32 func_L00_0052D6C0(void *arg0);

// Resolve each entry of the list arg1 to an object, link them to the found one and arg0.
s32 func_L00_00541FE8(s32 arg0, s32 *arg1) {
    s32 found = 0;
    s32 i;
    if (arg0 == 0 || func_L00_0051CE60(arg0) != 0) {
        for (i = 0; i < arg1[0]; i++) {
            found = func_L00_0052D6C0(((void **)arg1[1])[i]);
            if (found == 0) {
                func_L00_004F84C8(0xB, 0xDF, 0xA2, 0, 0);
                return 0;
            }
            if (func_L00_0051CE60(found) == 0) break;
            found = 0;
        }
        i--;
        if (found == 0) {
            func_L00_004F84C8(0xB, 0xDF, 0xA1, 0, 0);
            return 0;
        }
        for (; i >= 0; i--) {
            func_L00_0051CD28((void *)func_L00_0052D6C0(((void **)arg1[1])[i]), (void *)found);
        }
        if (arg0 != 0) {
            func_L00_0051CD28((void *)arg0, (void *)found);
        }
    }
    return 1;
}

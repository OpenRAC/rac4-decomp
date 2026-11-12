/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_005305F8(s32);

void func_L00_00541D98(s32 *arg0) {
    if (*arg0 == 1) {
        func_L00_005305F8(arg0[1]);
    }
}

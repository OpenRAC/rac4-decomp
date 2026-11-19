/* cflags: @ee29 -O2 -G0 */
#include "common.h"
extern void func_L00_00530B18(s32);
void func_L00_005422B8(s32 *arg0) {
    if (*arg0 == 1) {
        func_L00_00530B18(arg0[1]);
    }
}

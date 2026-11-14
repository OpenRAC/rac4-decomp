/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_003FE8B0(s32, s32 *, s32);
extern void func_00403330(s32 a0, s32 a1, s32 a2);
s32 func_003FE928(s32 a0, s32 *a1, s32 a2, s32 a3) {
    s32 r = func_003FE8B0(a0, a1, a3);
    if (r != 0) {
        return r;
    }
    func_00403330(*a1, a2, a3);
    return 0;
}

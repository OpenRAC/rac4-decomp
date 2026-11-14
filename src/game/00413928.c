/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_004138A8(s32, s32, s32);
extern void func_00403330(s32 a0, s32 a1, s32 a2);
s32 func_00413928(s32 a0, s32 a1, s32 a2, s32 *a3) {
    s32 r = func_004138A8(a0, a1, (s32)a3);
    if (r != 0) {
        return r;
    }
    func_00403330(*a3, a2, a1);
    return 0;
}

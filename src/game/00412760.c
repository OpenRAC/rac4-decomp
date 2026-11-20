/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0040EAE0(s32, s32);
extern s32 func_0040EB70(s32, s32, s32);
extern s32 func_0040EDE8(s32, s32, s32);
s32 func_00412760(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 *t1) {
    if (func_0040EAE0(a0, a2) >= 0) {
        *t1 = a1;
        if (a1 == a3) {
            return func_0040EDE8(a0, a2, t0);
        }
        return func_0040EB70(a0, a2, t0);
    }
    *t1 = -a3;
    if (a1 == a3) {
        return func_0040EDE8(a2, a0, t0);
    }
    return func_0040EB70(a0, a2, t0);
}

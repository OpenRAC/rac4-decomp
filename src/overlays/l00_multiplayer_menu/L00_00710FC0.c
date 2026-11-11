#include "common.h"

typedef struct { s32 f0[5]; s32 f14; } Type1;
extern s32 func_L00_0069E6E0(s32, f32, f32);
extern int func_L00_0069E7A8(int a, int b);
/* Check a handle and optionally invoke its float update. */
s32 func_L00_00710FC0(Type1 *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    if (arg0->f14 != 0) {
        if (func_L00_0069E7A8(arg0->f14, arg1) != 0) {
            if (arg1 != 0) return func_L00_0069E6E0(arg0->f14, fparg0, fparg1);
            return 1;
        }
    }
    return 0;
}

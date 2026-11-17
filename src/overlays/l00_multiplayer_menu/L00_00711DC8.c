#include "common.h"

extern s32 func_L00_0069E6E0(int a, f32 x, f32 y);
extern int func_L00_0069E7A8(int a, int b);

/* Applies the two floats to the object's handle at 0x5C when the flag is set; returns 1 if the handle is ready. */
s32 func_L00_00711DC8(void *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    if (*(s32 *)((u8 *)arg0 + 0x5C) != 0 && func_L00_0069E7A8(*(s32 *)((u8 *)arg0 + 0x5C), arg1) != 0) {
        if (arg1 != 0) {
            func_L00_0069E6E0(*(s32 *)((u8 *)arg0 + 0x5C), fparg0, fparg1);
        }
        return 1;
    }
    return 0;
}

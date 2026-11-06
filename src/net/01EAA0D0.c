/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 f0, f4, f8, fc, f10; } Type1;
/* Initializes a context and validates its bounds. */
s32 func_01EAA0D0(Type1 *arg0, u32 arg1, u32 arg2) {
    s32 result = 0;
    if (arg0 != NULL) {
        arg0->f10 = 0;
        arg0->f0 = arg1;
        arg0->f8 = arg1;
        arg0->f4 = arg2;
        arg0->fc = 0;
        if (arg1 == 0) {
            arg0->f10 = 2;
            return 0;
        }
        if (arg2 == 0 || arg1 >= arg2) {
            arg0->f10 = 2;
            return 0;
        }
        result = 1;
    }
    return result;
}

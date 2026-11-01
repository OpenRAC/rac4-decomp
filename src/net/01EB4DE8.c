/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
} Type1;

/* Compare the first words of two eight-byte values passed by value. */
s32 func_01EB4DE8(Type1 arg0, Type1 arg1) {
    return arg0.f0 == arg1.f0;
}

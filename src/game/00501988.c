/* cflags: @ee296 -O2 -G8 */
#include "common.h"

f32 D_00220AD4 = 0;
f32 D_00220AD8 = 0;
f32 D_00220AEC = 0;
f32 D_00220AF0 = 0;
f32 D_00220AF4 = 0;
f32 D_00220AF8 = 0;

/* Divide two pairs of globals and store the quotients in two more. */
void func_00501988(void) {
    f32 a = D_00220AD4;
    f32 b = D_00220AEC;
    f32 c = D_00220AD8;
    f32 d = D_00220AF0;

    D_00220AF4 = a / b;
    D_00220AF8 = c / d;
}

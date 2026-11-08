/* cflags: @ee296 -O2 -G0 -mno-split-addresses -Wa,-G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x2E20];
    f32 f2E20;
    char _p2E24[0x100];
    f32 f2F24;
};

s32 func_00512610(Type1 *arg0) {
    return arg0->f2E20 / arg0->f2F24 <= 0.200000003f;
}

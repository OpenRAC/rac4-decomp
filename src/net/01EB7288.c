/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 f0[0x1A4]; u16 f1A4; } Type1;
/* Copies the halfword when both pointers are valid. */
s32 func_01EB7288(Type1 *arg0, u16 *arg1) {
    if (arg1 == NULL) return 2;
    if (arg0 == NULL) return 2;
    *arg1 = arg0->f1A4;
    return 0;
}

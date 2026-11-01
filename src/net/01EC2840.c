/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 f0[0x38]; s32 f38; s32 f3C; } Type1;
/* Enables the object when its state permits it. */
s32 func_01EC2840(Type1 *arg0) {
    if (arg0 == NULL) return 2;
    if (arg0->f3C != 0) return 0xD6DA;
    arg0->f38 = 1;
    return 0;
}

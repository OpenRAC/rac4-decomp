/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 f0[0x19C]; u16 f19C; } Type1;
/* Reads the halfword into a word output, or returns 2 for null pointers. */
s32 func_01EB84B8(Type1 *arg0, s32 *arg1) {
    if (arg1 == NULL) return 2;
    *arg1 = 0;
    if (arg0 == NULL) return 2;
    *arg1 = arg0->f19C;
    return 0;
}

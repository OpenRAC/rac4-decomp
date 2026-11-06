/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 f0[0x5C]; u16 f5C; } Type1;
/* Clears the output and copies the context halfword when available. */
s32 func_01EBDEF0(Type1 *arg0, u16 *arg1) {
    *arg1 = 0;
    if (arg0 == NULL) return 0xD2F3;
    *arg1 = arg0->f5C;
    return 0;
}

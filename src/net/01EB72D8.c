/* cflags: -Os */
#include "common.h"

typedef struct { u8 f0[0x1CC]; u16 f1CC; } Type1;
/* Reads the halfword at offset 0x1CC when both pointers are valid. */
s32 func_01EB72D8(Type1 *arg0, u16 *arg1) {
    if (arg1 == NULL) return 2;
    *arg1 = 0;
    if (arg0 == NULL) return 2;
    *arg1 = arg0->f1CC;
    return 0;
}

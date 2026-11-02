#include "common.h"

/* Returns byte field 0x31 of the object from func_00595D00, or -1. */
extern void *func_00595D00(void);

s32 func_L01_005B4FC0(void) {
    u8 *p = (u8 *)func_00595D00();

    if (p == 0) {
        return -1;
    }
    return p[0x31];
}

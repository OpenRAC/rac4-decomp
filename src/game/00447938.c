#include "common.h"

/* Clears the 0x80-byte buffer at D_23A880 when D_221328 is 0, or calls func_00447550 when it is 2. */
extern void func_00447550();
extern void func_00453608(void *p, s32 v, s32 n);
extern s32 D_221328;
extern u8 D_23A880[];

void func_00447938(void) {
    if (D_221328 == 0) {
        func_00453608(D_23A880, -1, 0x80);
    } else if (D_221328 == 2) {
        func_00447550();
    }
}

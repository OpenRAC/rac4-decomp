/* cflags: -O2 -G8 */
#include "common.h"

typedef struct { char _p0[0x57]; u8 f57; char _p58[0x10]; u8 f68; } P;
P *D_002209F8 = 0; u8 D_00222000 = 0;
extern s32 D_0021DED0;
void func_004F81E0(void) {
    D_0021DED0 = 0;
    if ((D_002209F8->f57 != 0 || D_002209F8->f68 != 0) && D_00222000 != 0 && D_002209F8->f57 != 0) {
        D_0021DED0 = 1;
    }
}

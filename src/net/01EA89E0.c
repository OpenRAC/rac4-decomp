/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[8]; s32 f8; char _pc[8]; s32 f14; char _p18[8]; s32 f20; char _p24[8]; s32 f2C; } G;
extern G D_001B2148;
void func_01EA8A50(void);
void func_01EA89E0(s32 a, s32 b, s32 n) {
    if (a != 0) {
        D_001B2148.f8++;
        D_001B2148.f14 += a + n;
    }
    if (b != 0) {
        D_001B2148.f20++;
        D_001B2148.f2C += b + n;
    }
    func_01EA8A50();
}

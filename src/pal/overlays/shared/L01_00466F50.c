#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q[5];
} S_2BEE10;
extern S_2BEE10 D_003B2450;
extern void func_004149F0(S_2BEE10 *, u8 *, s32, s32);

/* PAL: from rac3-decomp's func_L01_0038E968 */
void func_L01_00466F50(u8 *a0) {
    S_2BEE10 m = D_003B2450;
    func_004149F0(&m, a0 + 16, 0, 0);
}

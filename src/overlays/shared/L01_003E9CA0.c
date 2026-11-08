#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q[5];
} S_2BEE10;
extern S_2BEE10 D_003B1BB0;
extern void func_L01_003DAF28(S_2BEE10 *, u8 *, s32, s32);

/* from rac3-decomp's func_L01_0038E968 */
void func_L01_003E9CA0(u8 *a0) {
    S_2BEE10 m = D_003B1BB0;
    func_L01_003DAF28(&m, a0 + 16, 0, 0);
}

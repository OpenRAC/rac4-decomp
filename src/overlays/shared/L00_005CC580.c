/* cflags: -mno-split-addresses */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern u128 D_002223B0;
extern u128 D_002223C0;
extern u128 D_002223D0;
extern u128 D_002223E0;
u128 *D_002223F0 = 0;

// Copy four consecutive 16-byte vectors from arg0 into four globals, then store the advanced pointer.
void func_L00_005CC580(u128 *arg0) {
    D_002223B0 = *arg0++;
    D_002223C0 = *arg0++;
    D_002223D0 = *arg0++;
    D_002223E0 = *arg0++;
    D_002223F0 = arg0;
}

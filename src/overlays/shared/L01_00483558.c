#include "common.h"

// Calls func_L01_00483578 with the moby and the first 16 bytes of its pvar.

typedef int u128 __attribute__((mode(TI)));

typedef struct Type1 {
    char _p0[0xAC];
    u128 *fAC;
} Type1;

extern void func_L01_00483578(Type1 *arg0, u128 arg1);

void func_L01_00483558(Type1 *arg0) {
    func_L01_00483578(arg0, *arg0->fAC);
}

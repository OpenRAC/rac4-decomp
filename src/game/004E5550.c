/* cflags: -G8 */
#include "common.h"

void func_0045CA60(s32, s32, s32);
extern s32 D_00171B2C[];
extern s16 D_1DFC48[];

s32 D_0021DAD8 = 0;

// Sets the three globals and calls func_0045CA60; the first two stores are a
// chained assignment, as retail's order needs.
void func_004E5550(void) {
    D_1DFC48[0] = (D_00171B2C[0] = 1);
    D_0021DAD8 = 1;
    func_0045CA60(1, 1, -1);
}

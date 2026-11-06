/* cflags: -mno-split-addresses */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 D_0021DE40;
extern u8 D_00222368[];
extern void func_00451788(u8 *, s32, u128 *, f32, f32, f32, f32, s32, s32, s32, s32);

// Copies three vectors from the first argument plus the second into a local array and
// passes it to func_00451788 with a value that cycles with the frame counter:
// (D_0021DE40 % ((n * 5 + 2) / 6)) / n * 2 - 1.
void func_L00_00582750(u128 *m, u128 v, s32 a2, s32 a3, s32 n, f32 x, f32 y) {
    u128 buf[4];

    buf[0] = m[0];
    buf[3] = v;
    buf[1] = m[1];
    buf[2] = m[2];
    func_00451788(D_00222368, 2, buf, 0.1f, x - y, x, (f32)(D_0021DE40 % ((n * 5 + 2) / 6)) / (f32)n * 2.0f - 1.0f,
                  a3, 0, a2, 2);
}

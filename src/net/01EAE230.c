/* cflags: @ee296 -O2 -G0 */
#include "common.h"

/* Applies a 256-byte byte-swapping keystream generator (index state at 0x100/0x101) to arg1 for arg2 bytes. */
void func_01EAE230(u8 *arg0, u8 *arg1, u32 arg2) {
    u8 i = arg0[0x100];
    u8 j = arg0[0x101];
    u32 n;
    u8 t;
    u8 v;

    for (n = 0; n < arg2; n++) {
        i = i + 1;
        t = arg0[i];
        j = j + t;
        v = t + arg0[j];
        arg0[i] = v - t;
        arg0[j] = v - arg0[j];
        arg1[n] ^= arg0[v];
    }
    arg0[0x100] = i;
    arg0[0x101] = j;
}

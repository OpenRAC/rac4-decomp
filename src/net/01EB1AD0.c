/* cflags: @ee296 -O2 -G0 */
#include "common.h"

// Packs each four bytes from arg1 into one word at arg0, low byte first, for
// arg2 bytes rounded up to whole words.
void func_01EB1AD0(s32 *arg0, u8 *arg1, u32 arg2) {
    s32 *d;
    u8 *s;
    u32 i;

    i = 0;
    if (arg2 != 0) {
        s = arg1;
        d = arg0;
        do {
            i += 4;
            *d = s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24);
            s += 4;
            d += 1;
        } while (i < arg2);
    }
}

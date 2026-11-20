/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_00411970(u64, u64, u64, u64 *, u64 *);
void func_004118D0(u64 a0, u64 a1, u64 a2, u64 *q, u64 *r) {
    u64 t[4];
    if (a0 > a1) {
        func_00411970(a0, a1, a2, &t[0], &t[1]);
        func_00411970(a0, t[1], a2 << 32, &t[2], &t[3]);
        *q = (t[0] << 32) + t[2];
        *r = t[3];
    } else {
        *q = -1;
        *r = 0;
    }
}

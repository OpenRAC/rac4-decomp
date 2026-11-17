/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *, s32, s32);
extern void *func_0011A370(void *, void *, s32);
extern void func_01EAD988(u8 *, u8 *);
void func_01EB4990(u8 *a, u8 *b) {
    u8 x[512];
    u8 y[512];
    func_0011A518(x, 0, sizeof(x));
    func_0011A518(y, 0, sizeof(y));
    func_0011A370(x, a, 0x40);
    func_0011A370(y, b, 0x40);
    func_01EAD988(x, y);
    func_0011A370(a, x, 0x40);
}

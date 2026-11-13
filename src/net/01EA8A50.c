/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_001B2148[];
extern void func_01EAB2C0(void *, u32 *);
extern void func_01EA8AC8(void *, u32);
extern void func_01EAB270(void *);
void func_01EA8A50(void) {
    u8 *s = D_001B2148;
    u32 x;
    func_01EAB2C0(s, &x);
    if (x >= 0x3E9) {
        func_01EA8AC8(s + 0x8, x);
        func_01EA8AC8(s + 0x14, x);
        func_01EA8AC8(s + 0x20, x);
        func_01EA8AC8(s + 0x2C, x);
        func_01EAB270(s);
    }
}

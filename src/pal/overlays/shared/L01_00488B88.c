#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern void func_00477AD0(u8 *, s32);
extern void func_L00_00621818(u8 *, s32, s32);
extern void func_L01_0059F8F8(u8 *, u8 *, s32, f32, f32);
extern void func_00485B78(u8 *);

// Outside states 7 and 9: calls func_00477AD0, func_L00_00621818(5) when bit 0 of +0x34 is
// clear, copies the position to the object at +0x2C0 of its block, then func_L01_0059F8F8
// on +0x340 and func_00485B78.
void func_L01_00488B88(u8 *arg0) {
    u8 *vars;
    u8 *other;

    if (arg0[0x20] == 9 || arg0[0x20] == 7) {
        return;
    }
    vars = *(u8 **)(arg0 + 0xAC);
    func_00477AD0(arg0, 0);
    if ((arg0[0x34] ^ 1) & 1) {
        func_L00_00621818(arg0, 5, -1);
    }
    other = *(u8 **)(vars + 0x2C0);
    if (other != NULL) {
        *(u128 *)(other + 0x10) = *(u128 *)(arg0 + 0x10);
    }
    func_L01_0059F8F8(arg0, vars + 0x340, 1, 0.0432f, 0.43200004f);
    func_00485B78(arg0);
}

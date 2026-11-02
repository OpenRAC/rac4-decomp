#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern f32 func_00472F70(void);
extern void func_L01_004B89E0(u8 *);
extern void func_L01_005BF430(u8 *, void *, s32, f32, f32);
extern void func_L01_005ACDA0(u8 *);
extern void func_L01_004B8BF8(u8 *);
extern void func_L01_004B91E0(u8 *);
extern void func_00474368(u8 *, s32, s32);
extern void func_L01_0059F8F8(u8 *, u8 *, s32, f32, f32);

// Resets the object's block, stores its position and a random value, runs its set-up calls and
// picks state 2, 2 or 0x12, 6 by the byte at +0x60D, then calls func_L01_0059F8F8 on +0x490 and
// +0x510.
void func_L01_004B86D0(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);

    vars[0x616] = 0;
    *(s16 *)(vars + 0x5E4) = 0;
    *(u128 *)(vars + 0x590) = *(u128 *)(arg0 + 0x10);
    *(s32 *)(vars + 0x604) = 0;
    *(f32 *)(vars + 0x600) = func_00472F70();
    *(s16 *)(vars + 0x5EA) = -1;
    func_L01_004B89E0(arg0);
    func_L01_005BF430(arg0, arg0 + 0x10, 0x8000, 1.0f, 4.0f);
    func_L01_005ACDA0(arg0);
    if (vars[0x60D] != 0) {
        func_L01_004B8BF8(arg0);
        func_00474368(arg0, 2, 2);
    } else {
        func_L01_004B91E0(arg0);
        func_00474368(arg0, 0x12, 6);
    }
    func_L01_0059F8F8(arg0, vars + 0x490, 1, 0.0432f, 0.43200004f);
    func_L01_0059F8F8(arg0, vars + 0x510, 2, 0.0432f, 0.43200004f);
}

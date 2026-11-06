#include "common.h"

extern void func_004E4DF0(s32);
extern void func_004E5070(s32, s32, s32, s32, s32, s32);
extern void func_004E4FA0(void);
extern s32 D_00221464;
extern s32 D_0023ABAC[];

s32 D_00220980 = 0;

/* Plays the cinematic numbered D_00220980 (func_004E4DF0), clears D_00221464, then calls
 * func_004E5070 with the 0x2C0000-byte block that ends at D_0023ABAC, and func_004E4FA0. */
void func_004F53C0(void) {
    func_004E4DF0(D_00220980);
    D_00221464 = 0;
    func_004E5070(0, 0, 0, 0, D_0023ABAC[0] - 0x2C0000, 0x2C0000);
    func_004E4FA0();
}

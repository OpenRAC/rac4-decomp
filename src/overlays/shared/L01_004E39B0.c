#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern void func_L00_005DE048(u8 *, s32, u128 *);
extern void func_L01_004E39E0(u128, f32);

void func_L01_004E39B0(u8 *arg0) {
    u128 buf;

    func_L00_005DE048(arg0, 0, &buf);
    func_L01_004E39E0(buf, 1.0f);
}

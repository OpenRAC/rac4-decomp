#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 D_0021E824;
f32 D_00220F68 = 1.0f;
f32 D_00220F6C = 1.0f;
f32 D_00220F70 = 1.0f;
f32 D_00220F74 = 1.0f;
f32 D_00220F78 = 1.0f;
extern void func_004E9498(f32, f32, f32, f32, void *, void *, void *, s32, s32);
extern s32 func_L01_00635CA8(f32, void *, void *, void *, void *, void *, void *, s32, s32, s32, s32);

void func_L01_0040AC50(u8 *obj, u8 *p1, u128 vec) {
    u8 *c = *(u8 **)(obj + 0xAC);
    f32 v = 6.5f;
    u128 local = vec;
    if (*(s32 *)(p1 + 0x1AE0) != 0) {
        v = D_00220F68;
    }
    if (D_0021E824 == 1) {
        func_004E9498(D_00220F6C, v, D_00220F78 * 0.016666668f, D_00220F70 * 0.00027777778f, p1, c + 0x20, &local, *(s32 *)(c + 0x44), 0);
    } else {
        func_004E9498(D_00220F6C, v, D_00220F74 * 0.016666668f, D_00220F70 * 0.00027777778f, p1, c + 0x20, &local, *(s32 *)(c + 0x44), 0);
    }
    *(s32 *)(c + 0x34) = func_L01_00635CA8(D_00220F70 * 0.00027777778f, p1, &local, c + 0x20, c, c + 0x10, obj, 1, 0, 0, 0);
}

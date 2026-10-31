/* cflags: -Wuninitialized -Wa,-G0 */
/* cflags:  -Wuninitialized -Wa,-G0 */
#include "common.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
typedef int solver_s128 __attribute__((mode(TI)));
typedef unsigned int solver_u128 __attribute__((mode(TI)));
typedef solver_s128 s128; typedef solver_u128 u128;
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))
#define M2C_R5900_PAND(a,b) __builtin_pand((u128)(a),(u128)(b))
#define M2C_R5900_POR(a,b) __builtin_por((u128)(a),(u128)(b))
#define M2C_R5900_PCPYLD(a,b) __builtin_pcpyld((u128)(a),(u128)(b))
#define M2C_R5900_PEXTLW(a,b) __builtin_pextlw((u128)(a),(u128)(b))
#define M2C_R5900_PEXTUW(a,b) __builtin_pextuw((u128)(a),(u128)(b))
#define M2C_R5900_PROT3W(a) __builtin_prot3w((u128)(a))

s32 func_00476D30(void *, f32, f32, f32, f32);      /* extern */
M2C_UNK func_004915B0(void *);                      /* extern */

void func_L00_00611390(void *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f1;
    f32 temp_f3;
    void *temp_16;
    void *temp_4;

    if (arg0 != NULL) {
        temp_4 = M2C_FIELD(arg0, void **, 0x20);
        temp_16 = arg0 + 0x20;
        if ((temp_4 == NULL) || ((M2C_FIELD(temp_4, u8 *, 0x20) & 0xF0) == 0xF0) || (M2C_FIELD(arg0, s128 *, 0x10) = (s128) M2C_FIELD(temp_4, s128 *, 0x10), temp_f3 = M2C_FIELD(temp_16, f32 *, 8), temp_f1 = M2C_FIELD(temp_16, f32 *, 4) + temp_f3, M2C_FIELD(temp_16, f32 *, 4) = temp_f1, (temp_f1 < 0.0f))) {
            func_004915B0(arg0);
            return;
        }
        if (temp_f1 > 0.6f) {
            temp_f0 = -temp_f3;
            M2C_FIELD(temp_16, f32 *, 8) = temp_f0;
            M2C_FIELD(temp_16, f32 *, 4) = (f32) (temp_f1 + temp_f0);
        }
        temp_f0_2 = M2C_FIELD(temp_16, f32 *, 0x10) + -0.02088f;
        M2C_FIELD(temp_16, f32 *, 0x10) = temp_f0_2;
        if (temp_f0_2 < 0.0f) {
            M2C_FIELD(temp_16, f32 *, 0x10) = 0.0f;
        }
        temp_f0_3 = M2C_FIELD(temp_16, f32 *, 0x14) + -0.017352002f;
        M2C_FIELD(temp_16, f32 *, 0x14) = temp_f0_3;
        if (temp_f0_3 < 0.0f) {
            M2C_FIELD(temp_16, f32 *, 0x14) = 0.0f;
        }
        temp_f0_4 = M2C_FIELD(temp_16, f32 *, 0x18) + -0.0018000001f;
        M2C_FIELD(temp_16, f32 *, 0x18) = temp_f0_4;
        if (temp_f0_4 < 0.0f) {
            M2C_FIELD(temp_16, f32 *, 0x18) = 0.0f;
        }
        M2C_FIELD(arg0, s32 *, 4) = func_00476D30(temp_4, M2C_FIELD(temp_16, f32 *, 0x10), M2C_FIELD(temp_16, f32 *, 0x14), M2C_FIELD(temp_16, f32 *, 0x18), M2C_FIELD(temp_16, f32 *, 4));
        temp_f0_5 = M2C_FIELD(temp_16, f32 *, 0xC) + 0.00132f;
        M2C_FIELD(temp_16, f32 *, 0xC) = temp_f0_5;
        if (temp_f0_5 > 1.0f) {
            M2C_FIELD(temp_16, f32 *, 0xC) = (f32) (temp_f0_5 - 1.0f);
        }
        M2C_FIELD(arg0, s8 *, 8) = (s8) (s32) (M2C_FIELD(temp_16, f32 *, 0xC) * 255.0f);
        M2C_FIELD(arg0, f32 *, 0xC) = (f32) ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), f32 *, 0x70) * 100000.0f * 30.0f) + 50000.0f);
    }
}

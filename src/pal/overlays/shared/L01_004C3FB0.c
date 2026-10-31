/* cflags: -O2 -G8 -Wa,-G0 */
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

f32 func_0046C940(void *);                          /* extern */
f32 func_00472EB8(f32, f32);                /* extern */
M2C_UNK func_00481810(void *, s128, f32);           /* extern */
M2C_UNK func_00481900(void *, M2C_UNK, void *, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_00481A48(void *, u8, M2C_UNK);         /* extern */
M2C_UNK func_L01_00597190(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32, f32, f32); /* extern */

extern int func_L01_004C4128(void *, int);
s32 func_L01_004C3FB0(void *arg0, s32 arg1) {
    void *temp_17;

    temp_17 = M2C_FIELD(arg0, void **, 0xAC);
    switch (arg1) {                                 /* irregular */
    case 0:
        M2C_FIELD(temp_17, f32 *, 0x498) = func_00472EB8(1.7f, 1.7f);
        break;
    case 1:
        func_00481810(arg0, M2C_FIELD(temp_17, s128 *, 0x500), M2C_FIELD(temp_17, f32 *, 0x498) * 0.020000001f);
        if ((func_0046C940(arg0) >= 11.0f) && (func_0046C940(arg0) <= 13.0f)) {
            func_L01_00597190(arg0, 2, 0x801, 0, 1, 0, 1.0f, (f32) M2C_FIELD(temp_17, u8 *, 0x352), 2.0f);
        }
        if (func_0046C940(arg0) >= 19.0f) {
            func_00481A48(arg0, M2C_FIELD(temp_17, u8 *, 0x123), 0);
        }
        break;
    case 4:
        func_00481900(arg0, 0xC, func_L01_004C4128, 0, 0, 0, 0.0f);
        break;
    }
    return 1;
}

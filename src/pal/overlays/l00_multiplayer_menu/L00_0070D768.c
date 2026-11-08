/* cflags: -Wuninitialized */
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

int D_00220ABC = 0;
s32 func_L00_0070D768(void) {
    s32 temp_3;

    temp_3 = D_00220ABC;
    if (temp_3 != 0) {
        D_00220ABC = M2C_FIELD(temp_3, s32 *, 0x19C);
        M2C_FIELD(temp_3, s32 *, 0x19C) = 0;
    }
    return temp_3;
}
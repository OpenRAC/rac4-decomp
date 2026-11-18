/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
typedef long long s128; typedef unsigned long long u128;
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))
#define M2C_R5900_PAND(a,b) __builtin_pand((u128)(a),(u128)(b))
#define M2C_R5900_POR(a,b) __builtin_por((u128)(a),(u128)(b))
#define M2C_R5900_PCPYLD(a,b) __builtin_pcpyld((u128)(a),(u128)(b))
#define M2C_R5900_PEXTLW(a,b) __builtin_pextlw((u128)(a),(u128)(b))
#define M2C_R5900_PEXTUW(a,b) __builtin_pextuw((u128)(a),(u128)(b))
#define M2C_R5900_PROT3W(a) __builtin_prot3w((u128)(a))
typedef char m2c_fpr_width[(sizeof(f32)==4)?1:-1];

extern s32 D_00222A90;

s32 func_L01_00526480(void *arg0) {
    void *temp_2;

    temp_2 = M2C_FIELD(((M2C_FIELD(arg0, s16 *, 0x84) << 5) + D_00222A90), void **, 0x1C);
    if (M2C_FIELD(temp_2, s32 *, 0x108) != 0) {
        M2C_FIELD(temp_2, s32 *, 0x108) = 0;
        return 1;
    }
    return 0;
}

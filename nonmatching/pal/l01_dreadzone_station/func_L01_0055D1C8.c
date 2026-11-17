/* Not matching yet: 15/19 (78.95%) relocation-masked positional words; 72/76 candidate/target bytes. One target word is missing; return ABI remains unproved. Reproduce: python tools/check_func.py --version pal func_L01_0055D1C8 nonmatching/pal/l01_dreadzone_station/func_L01_0055D1C8.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized -fno-delayed-branch */
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


void func_L01_0055D1C8(s32 arg0, void **arg1, s32 arg2) {
    s32 temp_2;
    s32 temp_4;
    void *temp_6;

    temp_4 = (arg2 < 0x100) ? arg2 : 0xFF;
    temp_2 = (temp_4 > 1) ? temp_4 : 2;
    temp_6 = *arg1;
    M2C_FIELD(temp_6, s32 *, 0x34) = temp_2;
    M2C_FIELD(temp_6, f32 *, 0x50) = (f32) (1.0f / (f32) temp_2);
}

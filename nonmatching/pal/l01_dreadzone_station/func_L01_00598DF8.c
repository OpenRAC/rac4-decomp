/* Not matching yet: 13/17 (76.47%) relocation-masked positional words; 68/68 candidate/target bytes. Absolute-value sequence and store order differ; caller ABI is unproved. Reproduce: python tools/check_func.py --version pal func_L01_00598DF8 nonmatching/pal/l01_dreadzone_station/func_L01_00598DF8.c --diff. Not part of the build. */
/* cflags:  -Wuninitialized */
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


f32 func_L01_00598DF8(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp_8;
    s32 var_2;
    s32 var_3;
    s32 var_5;
    s32 var_6;
    s32 var_7;

    var_7 = *arg0;
    temp_8 = 0 - arg2;
    var_2 = arg1 - var_7;
    var_3 = arg2 < var_2;
    var_2 = (var_3 != 0) ? arg2 : var_2;
    var_6 = var_2 < temp_8;
    var_2 = (var_6 != 0) ? temp_8 : var_2;
    var_7 += var_2;
    var_5 = arg1 - var_7;
    *arg0 = var_7;
    if (var_5 <= 0) {
        var_5 = 0 - var_5;
    }
    return (f32) var_5;
}

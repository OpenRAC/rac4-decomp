/* Not matching yet: 13/23 (56.52%) relocation-masked positional words; 96/92 candidate/target bytes. Global and argument types are hypotheses. Reproduce: python tools/check_func.py --version pal func_L41_003E3370 nonmatching/pal/l41_battledome_tower/func_L41_003E3370.c --diff. Not part of the build. */
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

extern u32 D_00222894;
extern u32 D_002228B0;

void *func_L41_003E3370(s32 arg0) {
    s32 var_2;
    u32 var_5;
    u32 var_6;
    u8 *temp_2;

    var_5 = D_00222894;
    var_6 = 0;
    var_2 = var_5 < (u32) D_002228B0;
    goto loop_2;
block_1:
    var_2 = var_5 < (u32) D_002228B0;
loop_2:
    if (var_2 == 0) {
        goto block_13;
    }
    if (M2C_FIELD(var_5, s16 *, 0xBC) == 0x266E) {
        goto block_5;
    }
    var_5 = var_5 + 0x100;
    goto block_1;
block_5:
    temp_2 = M2C_FIELD(var_5, u8 **, 0xAC);
    if (temp_2 != NULL) {
        goto block_8;
    }
    var_5 = var_5 + 0x100;
    goto block_1;
block_8:
    if (*temp_2 == arg0) {
        goto block_11;
    }
    var_5 = var_5 + 0x100;
    goto block_1;
block_11:
    var_6 = var_5;
block_13:
    return (void *) var_6;
}

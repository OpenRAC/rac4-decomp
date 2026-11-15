/* Not matching yet: 20/30 (66.67%) relocation-masked positional words; 124/120 candidate/target bytes, one extra word. Pointee bounds and return usage remain unproved. Reproduce: python tools/check_func.py --version pal func_L01_00428B58 nonmatching/pal/l01_dreadzone_station/func_L01_00428B58.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

/* 20/30 target positions match (66.67%) under relocation-masked positional
 * comparison; 124/120 bytes with one extra word. Branch scheduling differs.
 * The callee pointer argument follows selected code; input object bounds and
 * return use remain unproved. Verify with
 * tools/diff_func.py --version pal func_L01_00428B58. */
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

void func_004915B0(void *);                         /* extern */

void func_L01_00428B58(void *arg0) {
    void **var_16;
    void *temp_4;
    s32 var_17;
    s8 var_3;
    void *temp_18;

    var_17 = 3;
    temp_18 = M2C_FIELD(arg0, void **, 0xAC);
    var_16 = (void *)((unsigned char *)(temp_18) + (32));
    do {
        temp_4 = *var_16;
        var_17 = var_17 - 1;
        if (temp_4 != 0) {
            func_004915B0(temp_4);
            *var_16 = 0;
        }
        var_16 = (void **)((unsigned char *)(var_16) + (4));
    } while (var_17 >= 0);
    var_3 = 0x40;
    if (M2C_FIELD(temp_18, s32 *, 0x38) > 0) {
        var_3 = 0xFF;
    }
    M2C_FIELD(arg0, s8 *, 0x30) = var_3;
}

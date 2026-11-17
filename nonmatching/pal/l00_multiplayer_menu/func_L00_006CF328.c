/* Not matching yet: 16/21 (76.19%) relocation-masked positional words; 84/84 candidate/target bytes. The s64 local is a code-generation hypothesis. Reproduce: python tools/check_func.py --version pal func_L00_006CF328 nonmatching/pal/l00_multiplayer_menu/func_L00_006CF328.c --diff. Not part of the build. */
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

s32 func_L00_00703198(s32, s32);                    /* extern */

s32 func_L00_006CF328(void *arg0) {
    s64 var_2;

    var_2 = 0;
    if (func_L00_00703198(M2C_FIELD(arg0, s32 *, 0x26E4), M2C_FIELD(arg0, u8 *, 0x2F10)) != 0) {
        var_2 = M2C_FIELD(arg0, s32 *, 0x25D4) != 0x14;
    }
    return var_2;
}

/* Not matching yet: 18/19 (94.74%) relocation-masked positional words; 72/76 candidate/target bytes. One post-return instruction is omitted; entry ownership and callback ABI remain unproved. Reproduce: python tools/check_func.py --version pal func_L00_004F81B8 nonmatching/pal/l00_multiplayer_menu/func_L00_004F81B8.c --diff. Not part of the build. */
/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

/* 18/19 target positions match (94.74%) under relocation-masked positional
 * comparison; 72/76 bytes. One instruction after the return is omitted; its
 * entry ownership is unknown. The callback ABI and global owner remain
 * unproved. Verify with tools/diff_func.py --version pal func_L00_004F81B8. */
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

M2C_UNK func_L00_004F89C8(s32, s32, s32, const char *, s32); /* extern */
extern s32 (*D_00466850)();

s32 func_L00_004F81B8(void) {
    if (D_00466850 == NULL) {
        func_L00_004F89C8(26, 125, 14, 0, 0);
        return 0;
    }
    return D_00466850();
}

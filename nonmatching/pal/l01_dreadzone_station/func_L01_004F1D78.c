/* Not matching yet: 13/22 (59.09%) relocation-masked positional words; 92/88 candidate/target bytes. One extra word; global extent and indirect callee ABI remain unproved. Reproduce: python tools/check_func.py --version pal func_L01_004F1D78 nonmatching/pal/l01_dreadzone_station/func_L01_004F1D78.c --diff. Not part of the build. */
/* cflags: -mno-split-addresses -Wuninitialized */
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

M2C_UNK func_L01_006B7330(s32, void *, M2C_UNK, s32 *); /* extern */
extern s32 D_002225F0[];

void func_L01_004F1D78(void *arg0) {
    s32 temp_2;

    temp_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0xAC), void **, 0x4C), s32 (**)(s32), 8)(M2C_FIELD(arg0, s32 *, 0xB8));
    if (temp_2 != 0) {
        M2C_FIELD(arg0, s8 *, 0x67) = 9;
        func_L01_006B7330(temp_2, arg0, 4, D_002225F0);
        M2C_FIELD(arg0, s8 *, 0x67) = 0;
    }
}

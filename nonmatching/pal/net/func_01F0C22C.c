/* Not matching yet: 21/24 (87.50%) relocation-masked positional words; 96/96 candidate/target bytes. Global storage and the indirect method ABI remain unknown. Reproduce: python tools/check_func.py --version pal func_01F0C22C nonmatching/pal/net/func_01F0C22C.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

/* 21/24 target words match (87.50%) under relocation-masked positional
 * comparison; 96/96 bytes. Prologue scheduling differs. Matched callee
 * signatures are used; global storage and the indirect method ABI remain
 * unproved. Verify with tools/diff_func.py --version pal func_01F0C22C. */
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

s32 func_01EEE12C(void);                                /* extern */
s32 func_01EEE45C(void);                              /* extern */
s32 func_01EEED28(u8 *);                             /* extern */
extern s32 D_0016F72C;

s32 func_01F0C22C(void) {
    s32 var_2;
    void *temp_2;

    var_2 = D_0016F72C;
    if (var_2 == 0) {
        var_2 = func_01EEED28((u8 *)func_01EEE12C());
        if (var_2 != 0) {
            temp_2 = (void *)func_01EEE45C();
            M2C_FIELD(M2C_FIELD(temp_2, void **, 0x10), M2C_UNK (**)(void *), 0x18)(temp_2);
            var_2 = 1;
            D_0016F72C = 1;
        }
    }
    return var_2;
}



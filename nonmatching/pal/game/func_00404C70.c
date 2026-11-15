/* Not matching yet: 7/12 (58.33%) relocation-masked positional words; 28/48 candidate/target bytes. Five words after return are omitted; boundary and argument types remain uncertain. Reproduce: python tools/check_func.py --version pal func_00404C70 nonmatching/pal/game/func_00404C70.c --diff. Not part of the build. */
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

void func_00404C70(s32 arg0, s32 *arg1, s32 *arg2, void **arg3, void *arg4) {
    *arg1 = M2C_FIELD(arg4, s32 *, 0);
    *arg2 = M2C_FIELD(arg4, s32 *, 4);
    *arg3 = (void *)((unsigned char *)(arg4) + (8));
}

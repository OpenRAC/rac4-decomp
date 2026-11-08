/* cflags: -Wuninitialized */
#include "common.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
typedef int solver_s128 __attribute__((mode(TI)));
typedef unsigned int solver_u128 __attribute__((mode(TI)));
typedef solver_s128 s128; typedef solver_u128 u128;
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))
#define M2C_R5900_PAND(a,b) __builtin_pand((u128)(a),(u128)(b))
#define M2C_R5900_POR(a,b) __builtin_por((u128)(a),(u128)(b))
#define M2C_R5900_PCPYLD(a,b) __builtin_pcpyld((u128)(a),(u128)(b))
#define M2C_R5900_PEXTLW(a,b) __builtin_pextlw((u128)(a),(u128)(b))
#define M2C_R5900_PEXTUW(a,b) __builtin_pextuw((u128)(a),(u128)(b))
#define M2C_R5900_PROT3W(a) __builtin_prot3w((u128)(a))

s32 func_L00_005522A0(void *arg0) {
    s32 (*var_2)(s32);
    s32 var_4;
    void *var_3;

    var_3 = arg0;
    var_2 = NULL;
    if (var_3 != NULL) {
        var_2 = M2C_FIELD(var_3, s32 (**)(s32), 0);
        var_4 = M2C_FIELD(var_3, s32 *, 4);
        var_2 = (s32 (*)(s32)) (var_2(var_4) != 0);
    }
    return (s32) var_2;
}
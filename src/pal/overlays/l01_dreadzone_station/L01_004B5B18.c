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

s64 func_L01_004B5848(int arg0);
s32 func_L01_004B5B18(void *arg0) {
    u8 var_3;
    u32 var_2;
    s32 var_5;

    var_2 = M2C_FIELD(arg0, u32 *, 0xAC);
    var_3 = M2C_FIELD(var_2, u8 *, 0x458);
    var_5 = 0;
    if (var_3 == 0) {
        var_2 = (u32) (func_L01_004B5848((s32) arg0) != 0);
        var_5 = (s32) var_2;
    }
    return var_5;
}
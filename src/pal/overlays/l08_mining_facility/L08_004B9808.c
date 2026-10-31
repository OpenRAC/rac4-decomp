/* cflags: -O2 -G8 -mno-split-addresses */
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

M2C_UNK func_0041B550(s128, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s128); /* extern */
M2C_UNK func_004E2EF0(M2C_UNK, M2C_UNK, s32);       /* extern */
s32 func_L00_005A1078();                            /* extern */
extern s32 D_0021DE3C;
extern s128 D_00222550;

void func_L08_004B9808(s32 arg0, s128 *arg1) {
    func_0041B550(*arg1, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 0, 0, 0, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0, 0, 0, D_00222550);
    if ((D_0021DE3C == 1) || (func_L00_005A1078() != 0)) {
        func_004E2EF0(2, 0x110, arg0);
        return;
    }
    func_004E2EF0(2, 0, arg0);
}

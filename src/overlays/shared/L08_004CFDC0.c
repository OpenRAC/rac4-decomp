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

M2C_UNK func_003C64F8(s128, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s128); /* extern */
s32 func_00510AD0(void *);                          /* extern */
M2C_UNK func_00545408(void *, M2C_UNK, M2C_UNK);    /* extern */
void func_005D97B0(void *, M2C_UNK);             /* extern */
M2C_UNK func_005D9CE8(M2C_UNK, M2C_UNK, void *);    /* extern */
void func_L08_004CFFC0(void *);                     /* extern */
extern s128 D_002224D0;

void func_L08_004CFDC0(void *arg0) {
    M2C_UNK var_5;
    s32 var_3;
    s32 temp_3;
    u8 temp_3_2;
    void *temp_18;

    temp_3 = M2C_FIELD(arg0, u8 *, 0x20);
    temp_18 = M2C_FIELD(arg0, void **, 0xAC);
    if (temp_3 == 1) {
        goto block_9;
    }
    if ((s32) temp_3 < 2) {
        goto block_3;
    }
    goto block_6;
block_3:
    if (temp_3 == 0) {
        goto block_8;
    }
    return;
block_6:
    if (temp_3 == 2) {
        goto block_13;
    }
    return;
block_8:
    M2C_FIELD(arg0, s32 *, 0x98) = 0;
    M2C_FIELD(temp_18, s32 *, 4) = -1;
    func_00545408(arg0, 1, -1);
    return;
block_9:
    if (M2C_FIELD(temp_18, s32 *, 4) < 0) {
        goto block_19;
    }
    if (func_00510AD0(temp_18 + 4) == 0) {
        goto block_18;
    }
    func_00545408(arg0, 2, -1);
    goto block_18;
block_13:
    temp_3_2 = M2C_FIELD(arg0, u8 *, 0xBE);
    if (!((temp_3_2 ^ 1) & 1)) {
        goto block_15;
    }
    var_3 = 1;
    M2C_FIELD(arg0, u8 *, 0xBE) = (u8) (temp_3_2 | 1);
    goto block_16;
block_15:
    var_3 = 0;
block_16:
    if (var_3 == 0) {
        goto block_18;
    }
    func_003C64F8(M2C_FIELD(arg0, s128 *, 0x10), 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.5f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 0, 0, 0, 0x80800, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0, 0, 0, D_002224D0);
    func_005D9CE8(0, 0, arg0);
    func_L08_004CFFC0(M2C_FIELD(temp_18, void **, 0));
    M2C_FIELD(arg0, s32 *, 0x98) = 0;
    M2C_FIELD(arg0, u16 *, 0x34) = (u16) ((M2C_FIELD(arg0, u16 *, 0x34) | 0x41) & 0xEFFF);
    func_005D97B0(arg0, 1);
    M2C_FIELD(arg0, s32 *, 0x98) = 0;
    M2C_FIELD(arg0, u16 *, 0x34) = (u16) (M2C_FIELD(arg0, u16 *, 0x34) | 2);
block_18:
block_19:
    return;
}

/* cflags: -Wuninitialized */
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

int func_L01_006ACB58(void);
s64 func_L01_004DBC38(s64 arg0, void *arg1);
void *func_006ACB60(s32);                           /* extern */

void func_L01_004DC3D0(void *arg0, s32 arg1) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_3;
    s32 temp_3_2;
    s32 var_18;
    s32 var_2;
    s32 var_3;
    void *temp_17;
    void *temp_5;
    void *var_16;

    temp_17 = M2C_FIELD(arg0, void **, 0xAC);
    temp_2 = M2C_FIELD(temp_17, s32 *, 8);
    var_3 = 0;
    if (temp_2 != arg1) {
        var_3 = temp_2 != 0xA;
    }
    M2C_FIELD(temp_17, s32 *, 8) = arg1;
    M2C_FIELD(temp_17, s8 *, 5) = 1;
    if (var_3 != 0) {
        var_16 = func_006ACB60(0);
        var_18 = 0;
while (var_18 < func_L01_006ACB58()) {

            if (var_16 != NULL) {
                temp_5 = M2C_FIELD(var_16, void **, 0x2B0);
                if ((temp_5 != NULL) && (M2C_FIELD(temp_5, s16 *, 0xBC) != 0x10C2) && (M2C_FIELD(var_16, s32 *, 0x2B8) == 0) && (M2C_FIELD(var_16, s32 *, 0x2BC) == 0) && (func_L01_004DBC38((s32) arg0, temp_5) != 0)) {
                    temp_3 = M2C_FIELD(var_16, s32 *, 0x30C);
                    if ((temp_3 != 0xA) && (temp_3 != M2C_FIELD(temp_17, s32 *, 8))) {
                        temp_2_2 = M2C_FIELD(var_16, s32 *, 0x2D8) | 0x400;
                        M2C_FIELD(var_16, s32 *, 0x2D8) = temp_2_2;
                        temp_3_2 = M2C_FIELD(temp_17, s32 *, 8);
                        if (temp_3_2 == 0) {
                            var_2 = (temp_2_2 & 0xFFFFFDFF) | 0x100;
                            goto block_16;
                        }
                        if (temp_3_2 == 1) {
                            var_2 = (temp_2_2 & 0xFFFFFEFF) | 0x200;
block_16:
                            M2C_FIELD(var_16, s32 *, 0x2D8) = var_2;
                        }
                    }
                }
            }
            var_18 += 1;
            var_16 = func_006ACB60(var_18);

        }
    }
}

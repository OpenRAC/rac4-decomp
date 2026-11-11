/* cflags: -G0 -Wuninitialized */
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

s32 func_0047BA40(s128, s32);
s32 func_00556D90(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_0046D3E8(void *);
M2C_UNK func_L13_0046D408(void *);
M2C_UNK func_L13_0046D498(void *);
extern void *D_00362E38[];

void func_L13_0046D2E8(void *arg0) {
    s32 temp_4;
    s32 temp_5;
    s32 var_17;
    u8 temp_3;
    void **var_16;
    void *temp_19;
    void *var_3;

    temp_3 = M2C_FIELD(arg0, u8 *, 0x20);
    temp_19 = M2C_FIELD(arg0, void **, 0xAC);
    switch (temp_3) {
    case 0:
        func_0046D3E8(arg0);
        return;
    case 1:
        var_17 = 9;
        var_3 = D_00362E38[0];
        var_16 = D_00362E38;
        do {
            if (var_3 != NULL) {
                temp_5 = M2C_FIELD(temp_19, s32 *, 0x18);
                if ((temp_5 >= 0) && (func_0047BA40(M2C_FIELD(var_3, s128 *, 0xA0), temp_5) != 0)) {
                    func_L13_0046D408(arg0);
                }
            }
            var_16 = (void **)((unsigned char *)(var_16) + (4));
            var_17 = var_17 - 1;
            var_3 = *var_16;
        } while (var_17 >= 0);
        break;
    case 2:
        temp_4 = M2C_FIELD(temp_19, s32 *, 0x1C);
        if (temp_4 >= 0) {
            if (func_00556D90(temp_4, -1, 0) == 0) {
                func_L13_0046D498(arg0);
            }
        }
        break;
    }
}

/* cflags: @ee29 -O2 -G0 -Wuninitialized */
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
typedef char m2c_fpr_width[(sizeof(f32)==4)?1:-1];

s128 func_L01_00469318(void *arg0) {
    void *temp_3;

    temp_3 = M2C_FIELD(arg0, void **, 0xAC);
    if (M2C_FIELD(temp_3, s32 *, 0x320) == 0) {
        return M2C_FIELD(temp_3, s128 *, 0x4B0);
    }
    return M2C_FIELD(temp_3, s128 *, 0x310);
}

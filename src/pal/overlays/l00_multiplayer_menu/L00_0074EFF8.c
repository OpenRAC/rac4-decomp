/* cflags: -O2 -G8 -Wuninitialized */
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

M2C_UNK func_L00_0071F2E0();                        /* extern */
M2C_UNK func_L00_0071FCE8(void *);                  /* extern */
extern void *D_00220DD4;

void func_L00_0074EFF8(void *arg0) {
    M2C_FIELD(D_00220DD4, u8 *, 0x114) = (u8) M2C_FIELD(arg0, u8 *, 0x260);
    func_L00_0071F2E0();
    func_L00_0071FCE8(arg0);
}
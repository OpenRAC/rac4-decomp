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

M2C_UNK func_0045DFC8(s32, s32, s32, s32, f32, f32, f32, f32); /* extern */
s32 func_L15_004D8480(void *, s32, s32, s32);       /* extern */
extern s32 D_0021DE40;

void func_L15_004D8BC0(void *arg0) {
    s32 temp_2;
    void *temp_16;

    temp_16 = M2C_FIELD(arg0, void **, 0xAC);
    if (M2C_FIELD(temp_16, s32 *, 0x250) <= 0) {
        temp_2 = func_L15_004D8480((void *)((unsigned char *)(temp_16) + (588)), 2, 11020, 11021);
        M2C_FIELD(temp_16, s32 *, 0x218) = temp_2;
        if (temp_2 >= 0) {
            M2C_FIELD(temp_16, s32 *, 0x250) = (s32) D_0021DE40;
            M2C_FIELD(temp_16, s32 *, 0x21C) = (s32) D_0021DE40;
            func_0045DFC8((s16) M2C_FIELD(temp_16, s32 *, 0x218), 4294967295, 2, 0, 0.75f, 1.0f, 0.0f, 64.0f);
        }
    }
}

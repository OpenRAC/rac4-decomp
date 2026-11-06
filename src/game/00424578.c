/* cflags:  -Wuninitialized */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;

M2C_UNK func_00452790(M2C_UNK *, void *, u8 (*)[]); /* extern */
M2C_UNK func_00424378(f32);                     /* extern */
extern M2C_UNK D_00221288;
extern u8 D_003CFC88[];

void func_00424578(void *arg0) {
    f32 temp_f0;
    void *temp_16;

    temp_16 = M2C_FIELD(arg0, void **, 0xAC);
    temp_f0 = M2C_FIELD(temp_16, f32 *, 0x6C) + 1.0f;
    M2C_FIELD(temp_16, f32 *, 0x6C) = temp_f0;
    func_00424378(temp_f0);
    func_00452790(&D_00221288, temp_16 + 0x80, (u8 (*)[]) D_003CFC88);
}

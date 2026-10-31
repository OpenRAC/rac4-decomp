/* cflags:  -Wuninitialized */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;

M2C_UNK func_00452FB8(M2C_UNK *, void *, u8 (*)[]); /* extern */
M2C_UNK func_L01_00435870(f32);                     /* extern */
extern M2C_UNK D_00222C28;
extern u8 D_003B1F10[];

void func_L01_00435A70(void *arg0) {
    f32 temp_f0;
    void *temp_16;

    temp_16 = M2C_FIELD(arg0, void **, 0xAC);
    temp_f0 = M2C_FIELD(temp_16, f32 *, 0x40) + 1.0f;
    M2C_FIELD(temp_16, f32 *, 0x40) = temp_f0;
    func_L01_00435870(temp_f0);
    func_00452FB8(&D_00222C28, temp_16 + 0x50, (u8 (*)[]) D_003B1F10);
}

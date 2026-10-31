/* cflags: -mno-split-addresses -Wuninitialized */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;
void func_L01_004DC2A0(void * arg0, float arg1);
int func_004535C0(void * arg0, int arg1, float arg2, float arg3);
extern u8 D_00222C28[];
void func_L01_004DCA80(void *arg0) {
    void *temp_16;

    temp_16 = M2C_FIELD(arg0, void **, 0xAC);
    if ((temp_16 != NULL) && (func_004535C0(D_00222C28, temp_16 + 0x20, (f32) M2C_FIELD(arg0, s16 *, 0x32), 2.0f * M2C_FIELD(temp_16, f32 *, 0xC)) != -1)) {
        func_L01_004DC2A0(arg0, 1.0f - M2C_FIELD(temp_16, f32 *, 8));
    }
}

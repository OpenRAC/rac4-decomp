/* cflags: -Os -G8 -Wuninitialized */
#include "common.h"
typedef long long s128;
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

void func_L01_00433DE0(void *, void *, void *, s32, s128 *); /* extern */

void func_L01_00433E50(void *arg0) {
    s128 sp0;
    void *temp_5;
    void *temp_5_2;
    void *temp_16;

    temp_16 = M2C_FIELD(arg0, void **, 0xAC);
    temp_5 = M2C_FIELD(temp_16, void **, 0x14);
    if (temp_5 != 0) {
        func_L01_00433DE0((void *)((unsigned char *)(temp_16) + (64)), temp_5, (void *)((unsigned char *)(temp_16) + (32)), 0, &sp0);
        M2C_FIELD(arg0, s128 *, 0x10) = sp0;
    }
    temp_5_2 = M2C_FIELD(temp_16, void **, 0x18);
    if (temp_5_2 != 0) {
        func_L01_00433DE0((void *)((unsigned char *)(temp_16) + (64)), temp_5_2, (void *)((unsigned char *)(temp_16) + (48)), 1, &sp0);
    }
}

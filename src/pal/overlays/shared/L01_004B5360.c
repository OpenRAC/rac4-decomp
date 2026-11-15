/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

void func_0047C5B8(void *);
s64 func_L01_004B5118(void *arg0);
void func_L01_004B5360(void *arg0) {
    u8 temp_7;
    void *temp_6;

    temp_6 = M2C_FIELD(arg0, void **, 0xAC);
    temp_7 = M2C_FIELD(temp_6, u8 *, 0x687);
    M2C_FIELD(temp_6, s16 *, 0x67C) = 0x11;
    M2C_FIELD(temp_6, s16 *, 0x67E) = -1;
    M2C_FIELD(temp_6, s32 *, 0x50) = (s32) (M2C_FIELD(temp_6, s32 *, 0x50) | 0x40);
    if (temp_7 < 0xFFU) {
        M2C_FIELD(temp_6, u8 *, 0x687) = (u8) (temp_7 + 1);
    }
    func_0047C5B8(arg0);
    func_L01_004B5118(arg0);
}

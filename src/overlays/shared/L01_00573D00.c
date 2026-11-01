#include "common.h"

extern void func_L01_00571F50(u16, s32);
extern u16 D_00222C3C;
extern s32 D_0021DDB8;
extern u8 D_0024F120[];

// Walks the list of 0x30-byte entries from D_00222C3C (end 0x801) and calls func_L01_00571F50 on
// each one whose +0x24 value plus 180 is below D_0021DDB8; returns 1.
s32 func_L01_00573D00(void) {
    u16 i = D_00222C3C;

    while (i != 0x801) {
        u8 *e = D_0024F120 + i * 0x30;
        s32 now = D_0021DDB8;
        u16 next = *(u16 *)(e + 0x28);
        if (now >= 0xB5 && *(u16 *)(e + 0x24) + 0xB4 < now) {
            func_L01_00571F50(i, now);
        }
        i = next;
    }
    return 1;
}

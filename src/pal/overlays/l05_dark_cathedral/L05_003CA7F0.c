#include "pal/l05_00363038.h"

extern s32 func_00472DF8(void *, s32, s32);
extern void func_L01_00572A68(s32, s32, s32);
extern s32 D_0021DAF0;
extern u8 D_001F7750[];

// Walks the entries of D_00363038; for each live one that func_00472DF8 accepts, calls func_L01_00572A68 when the time window at D_001F7750 is clear.
void func_L05_003CA7F0(void *arg0) {
    s32 *link = *(s32 **)((u8 *)arg0 + 0xAC);

    if (link != NULL && *link != -1) {
        s32 i;
        u8 **p = D_00363038;
        u8 *e = *p;
        for (i = 0; i < 10; i++) {
            if (e != NULL && func_00472DF8(e + 0xA0, *link, 0) != 0) {
                u8 *w = D_001F7750;
                if (*(u16 *)(w + 0x24) == 0 || (u32)(D_0021DAF0 - *(s32 *)(w + 0x28)) > 180000U) {
                    func_L01_00572A68(0x2F9C, 0x672, 2);
                }
            }
            p++;
            e = *p;
        }
    }
}

#include "common.h"

extern u8 D_004EB818[];

// Copy 0x35 rows of count halfwords from src into 10-byte rows at D_004EB818.
void func_L00_0073FB40(s32 src, s32 count) {
    s32 i = 0;
    do {
        if (count > 0) {
            s32 off = i * 10;
            u16 *d = (u16 *)(off + D_004EB818);
            u16 *s = (u16 *)(off + src);
            s32 n = count;
            do {
                *d = *s;
                n--;
                s++;
                d++;
            } while (n != 0);
        }
        i++;
    } while (i < 0x35);
}

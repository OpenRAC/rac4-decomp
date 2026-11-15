#include "common.h"

extern u32 D_222914;
extern u16 *D_288D20[];

// Set or clear bit 2 of byte 0xBE on each object listed in table arg0, until an entry has its top bit set.
void func_L13_00556EA0(s32 arg0, s32 arg1) {
    u16 *first = D_288D20[arg0];
    u16 *p;

    if (first != 0) {
        p = first;
        do {
            u32 obj = ((*p & 0x7FFF) << 8) + D_222914;
            u8 v;

            if (arg1 != 0) {
                v = *(u8 *)(obj + 0xBE) | 4;
            } else {
                v = *(u8 *)(obj + 0xBE) & 0xFB;
            }
            *(u8 *)(obj + 0xBE) = v;
        } while (*(s16 *)p++ >= 0);
    }
}

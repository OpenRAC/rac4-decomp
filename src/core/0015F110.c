#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern s32 func_01EC94C0();
extern s32 D_01F31380[];

// Claims the free entry of D_01F31380 that func_01EC94C0 selects for the object it reports, initializing its fields and clearing the 32 bytes at +0x94.
void func_0015F110(void) {
    u8 *sp0 = NULL;
    u8 *obj;
    u8 *rec;
    s32 val;
    s32 i;

    if (func_01EC94C0(&sp0) == 0) {
        obj = *(u8 **)(sp0 + 0x1C);
        rec = (u8 *)D_01F31380 + *(s32 *)(obj + 0x54) * 0xAD0;
        if (*(u8 **)(rec + 4) == NULL) {
            val = *(s32 *)(sp0 + 8);
            *(s16 *)(rec + 8) = 0;
            *(s32 *)(rec + 0) = val;
            *(s16 *)(rec + 0xA) = 1;
            *(s32 *)(rec + 0xA9C) = -1;
            func_0011A518(rec + 0x58, 0, 0xA40);
            *(u8 **)(rec + 4) = obj;
            i = 0;
            do {
                *(u8 *)(*(u8 **)(rec + 4) + i + 0x94) = 0xFF;
                i++;
            } while (i < 0x20);
            *(s32 *)(*(u8 **)(rec + 4) + 0xB4) = 0;
            *(s16 *)(rec + 0xE) = 0;
        }
    }
}

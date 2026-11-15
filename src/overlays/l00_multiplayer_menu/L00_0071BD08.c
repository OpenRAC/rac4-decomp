#include "common.h"

extern void func_L00_00624A78(s32 param_a, s32 param_b, s32 source);
extern void func_L00_00624AF0(s32, u32);
extern s32 func_L00_0069D028(s32, s32);
u32 D_00220D78 = 0;

/* Counts a new user of the object and, for the first two, runs the helper calls. */
void func_L00_0071BD08(void *arg0, s32 arg1) {
    u32 n;

    if (*(u8 *)((u8 *)arg0 + 0xA9) != 1) {
        n = D_00220D78 + 1;
        D_00220D78 = n;
        *(u32 *)((u8 *)arg0 + 0x254) = n;
        if (D_00220D78 < 2) {
            func_L00_0069D028(*(s32 *)((u8 *)arg0 + 0x240) | arg1, 0);
            if (*(u8 *)((u8 *)arg0 + 0xA9) != 1) {
                if (*(u32 *)((u8 *)arg0 + 0x254) < 2) {
                    func_L00_00624AF0(0, *(u32 *)((u8 *)arg0 + 0x254));
                }
                if (*(u8 *)((u8 *)arg0 + 0xA9) != 1) {
                    if (*(u32 *)((u8 *)arg0 + 0x254) < 2) {
                        func_L00_00624A78(0, *(u32 *)((u8 *)arg0 + 0x254), *(s32 *)((u8 *)arg0 + 0x240) | arg1);
                    }
                }
            }
        }
    }
}

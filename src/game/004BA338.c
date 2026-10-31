#include "common.h"

extern u8 D_00171D38[];
extern s32 D_003D9598[];
extern s32 D_2217E0;
extern u8 D_30A4E0[];
extern void func_00497980(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00505238(s32, s32);

/* Toggles byte 0xB3 of D_00171D38 when arg0 is set, then passes a 0x30-byte slot of D_30A4E0 to func_00505238. */
void func_004BA338(s32 arg0) {
    if (arg0 != 0) {
        D_00171D38[0xB3] = (u8)(D_00171D38[0xB3] == 0);
        func_00497980(0x10);
    }
    func_00505238(func_004A1A60(&D_2217E0, D_003D9598[0]), (s32)(D_00171D38[0xB3] * 0x30 + D_30A4E0));
}

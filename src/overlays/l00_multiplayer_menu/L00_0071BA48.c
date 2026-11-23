#include "common.h"

typedef struct {
    u8 pad0[0xA9];
    u8 unkA9;
    u8 padAA[0x238 - 0xAA];
    s32 unk238;
    s32 unk23C;
    u32 unk240;
    u8 pad244[0x250 - 0x244];
    u32 unk250;
} Type0;

extern s32 func_L00_00623A60(s32, s32, s32, s32);
extern s32 func_L00_00623B08(s32, s32);
extern s32 func_L00_00623B50(s32);
extern s32 func_L00_00623C30(s32, s32, s32);

void func_L00_0071BA48(Type0 *arg0, u32 arg1) {
    s32 temp_s1;
    u32 temp_a1;
    temp_a1 = arg0->unk250;
    if (temp_a1 < 4) {
        temp_s1 = (arg0->unkA9 ^ 1) ? 0 : 4;
        if (arg0->unk238 == arg1) {
            if (arg1 != 0xFFFFFFFFU) return;
        }
        arg0->unk238 = arg1;
        if (arg1 == 0xFFFFFFFFU) {
            func_L00_00623B50(temp_s1);
            return;
        }
        func_L00_00623A60(temp_s1, temp_a1, arg0->unk240 | arg1, 0);
        func_L00_00623C30(temp_s1, arg0->unk250, 1);
        func_L00_00623B08(temp_s1, arg0->unk250);
    }
}

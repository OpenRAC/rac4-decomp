#include "common.h"

extern s32 D_0021EE54;
extern u8 D_001170D0[];
extern s32 D_001DFCD4[];
extern s32 D_00237100[];

s32 D_002209FC = 0;

void func_004E8378(s32 arg0);
void func_004F3640(s32 arg0);
void func_00464878(s32 arg0);
void func_004F5808(void);
void func_004F5C08(void);

s32 func_004F5DA8(void)
{
    s32 result;

    func_004E8378((s32)D_001170D0);
    if (D_0021EE54 == 1) {
        return 0;
    }
    result = 0;
    D_00237100[0x1E]++;
    D_00237100[0x1D]++;
    if (D_00237100[0x1D] == 1) {
        func_004F3640(D_001DFCD4[0]);
    }
    if (*(s16 *)&D_00237100[0x20] >= D_00237100[0x1D]) {
        if (D_00237100[0x1E] >= 0x50) {
            D_00237100[0x1F]++;
            func_00464878(D_00237100[0x1F]);
        }
        func_004F5808();
        func_004F5C08();
    } else {
        result = 1;
        D_002209FC++;
    }
    return result;
}

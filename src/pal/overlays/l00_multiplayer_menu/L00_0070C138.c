#include "pal/profile_001721E0.h"

extern s32 D_00223338;
extern s32 func_00154D20(s32);
extern s32 func_00154BA8(void);
extern s32 func_00126A90(void);
extern s32 func_00126A30(s32, s32);
void func_L00_0070C138(void)
{
    func_00154D20(D_001721E0.region20.words.f28);
    D_001721E0.region20.words.f28 = -1;
    func_00154BA8();
    func_00126A30(func_00126A90(), D_00223338);
}

#include "common.h"

extern s32 func_00506BB8(void);
extern s32 func_00506B70(s32);
extern void *func_004D8168(s32);
extern void func_00502508(void *);
extern s32 func_00506D28(void *);
extern void func_004985F0(s32);
u8 D_0021FCB9 = 0;

/* Reset the selected slot while preserving the active slot and notification flag. */
void func_004D82E0(s32 index)
{
    s32 saved = func_00506BB8();
    func_00506B70(index);
    func_00502508(func_004D8168(index));
    func_00506D28(func_004D8168(index));
    func_00506B70(saved);
    if (!D_0021FCB9)
        func_004985F0(11);
    else
        D_0021FCB9 = 0;
}

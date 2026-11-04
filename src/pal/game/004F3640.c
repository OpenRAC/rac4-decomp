#include "common.h"

extern s32 D_003288D0[];
extern s32 D_00328910[];
extern s32 D_00328890[];
extern void func_00159130(void);
extern void func_00159138(void);
extern void func_004F3630(s32, s32 *);
extern void func_00158790(s32, s32, s32, s32, s32, s32, void (*)(s32, s32 *), s32 *);
extern s32 func_00157FA8(void);

s32 D_00220A00 = 0;

/* Initialize an indexed callback slot. */
void func_004F3640(s32 arg0)
{
    s32 index;
    s32 *slot;
    if (arg0 < 0 || arg0 >= D_00220A00) {
        return;
    }
    index = D_003288D0[arg0];
    slot = &D_00328910[index];
    *slot = -1;
    func_00159130();
    func_00158790(D_00328890[index], 0, 0x400, 0, 0, 0, func_004F3630, slot);
    func_00159138();
    func_00157FA8();
}

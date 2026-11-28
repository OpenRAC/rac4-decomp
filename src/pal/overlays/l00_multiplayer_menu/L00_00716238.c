/* cflags: @ee296 -O2 -G8 -fno-optimize-sibling-calls -mno-split-addresses */
#include "common.h"

extern s32 D_L00_00220CE8;
extern s32 D_L00_00220CEC[];
extern s32 D_L00_00220CF8;

extern void func_004E8758(u32 mask);
extern void func_004E8448(void);
extern void func_004E8560(void);

void func_L00_00716238(void)
{
    D_L00_00220CE8 = 0;
    D_L00_00220CEC[0] = 0;
    D_L00_00220CF8 = 0;

    func_004E8758(1);
    func_004E8448();
    func_004E8560();
}

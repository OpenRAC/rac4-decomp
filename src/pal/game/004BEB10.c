#include "common.h"
u8 D_0021F9DB = 0;
s32 D_0021F9D4 = 0;
extern char D_0030B358[];
extern s32 func_00506BB8(void);
extern void func_0049BED8(s32, s32);

/* Marks the mode active and snapshots the selected record value. */
void func_004BEB10(void)
{
    s32 i = func_00506BB8();
    char *p = D_0030B358 + i * 600;
    D_0021F9DB = 1;
    D_0021F9D4 = *(s32 *)(p + 0x240);
    func_0049BED8(i, 21);
}

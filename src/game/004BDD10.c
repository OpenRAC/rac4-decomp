#include "common.h"
u8 D_0021F93B = 0;
s32 D_0021F934 = 0;
extern char D_0030B358[];
extern s32 func_00505B20(void);
extern void func_0049B1A0(s32, s32);

/* Marks the mode active and snapshots the selected record value. */
void func_004BDD10(void)
{
    s32 i = func_00505B20();
    char *p = D_0030B358 + i * 600;
    D_0021F93B = 1;
    D_0021F934 = *(s32 *)(p + 0x240);
    func_0049B1A0(i, 21);
}

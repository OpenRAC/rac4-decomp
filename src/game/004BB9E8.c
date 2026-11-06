#include "common.h"

extern s32 func_00505B20(void);
extern void func_004A1310(void *);
extern void func_004A1358(void *);
extern void func_00497980(s32);
extern char D_0030A6F0[];

/* Change the current selection, play its sound and request an update. */
void func_004BB9E8(s32 forward)
{
    char *p = D_0030A6F0 + func_00505B20() * 0x534;
    char *menu;
    if (forward) {
        menu = p + 0x4C8;
        func_004A1310(menu);
    } else {
        menu = p + 0x4C8;
        func_004A1358(menu);
    }
    if (*(s32 *)(menu + 0x50) >= 2)
        func_00497980(10);
    else
        func_00497980(4);
    *(s32 *)(p + 4) |= 5;
}

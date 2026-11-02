#include "common.h"

extern s32 func_00506BB8(void);
extern void func_004A2048(void *);
extern void func_004A2090(void *);
extern void func_004985F0(s32);
extern char D_0030A6F0[];

/* Change the current selection, play its sound and request an update. */
void func_004BC7E8(s32 forward)
{
    char *p = D_0030A6F0 + func_00506BB8() * 0x534;
    char *menu;
    if (forward) {
        menu = p + 0x4C8;
        func_004A2048(menu);
    } else {
        menu = p + 0x4C8;
        func_004A2090(menu);
    }
    if (*(s32 *)(menu + 0x50) >= 2)
        func_004985F0(10);
    else
        func_004985F0(4);
    *(s32 *)(p + 4) |= 5;
}

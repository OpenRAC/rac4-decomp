#include "common.h"

extern void func_004E8758(s32);
extern void func_00458E88(void);
extern void func_004590E8(s32, s32, s32, s32, s32, s32);
extern void func_004F97D8(void);
extern s32 D_0021DEF4;

/* Initialize the display, choose its mode bounds and refresh the output. */
void func_0045A100(void)
{
    func_004E8758(1);
    func_00458E88();
    if (D_0021DEF4)
        func_004590E8(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    else
        func_004590E8(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    func_004F97D8();
}

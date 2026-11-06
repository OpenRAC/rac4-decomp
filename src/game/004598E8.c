#include "common.h"

extern void func_004E7830(s32);
extern void func_00458670(void);
extern void func_004588D0(s32, s32, s32, s32, s32, s32);
extern void func_004F8758(void);
extern s32 D_0021DE6C;

/* Initialize the display, choose its mode bounds and refresh the output. */
void func_004598E8(void)
{
    func_004E7830(1);
    func_00458670();
    if (D_0021DE6C)
        func_004588D0(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    else
        func_004588D0(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    func_004F8758();
}

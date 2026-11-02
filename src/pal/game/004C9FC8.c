#include "common.h"
extern u8 D_0030E532[];
extern char *func_0045E850(s32);
extern void func_004C9F90(s32);
extern void func_0049BF40(s32);
extern void func_0049F4C8(s32, char *, void (*)(s32), s32,
                          s32, s32, s32, f32);

/* Opens the confirmation view or restores state depending on the flag. */
void func_004C9FC8(void)
{
    if (D_0030E532[0])
        func_0049F4C8(0, func_0045E850(0x3515), func_004C9F90,
                      3, 0, 0, 0, -1.0f);
    else
        func_0049BF40(0);
}

#include "common.h"
extern u8 D_0030E532[];
extern char *func_0045E038(s32);
extern void func_004C9168(s32);
extern void func_0049B208(s32);
extern void func_0049E790(s32, char *, void (*)(s32), s32,
                          s32, s32, s32, f32);

/* Opens the confirmation view or restores state depending on the flag. */
void func_004C91A0(void)
{
    if (D_0030E532[0])
        func_0049E790(0, func_0045E038(0x3515), func_004C9168,
                      3, 0, 0, 0, -1.0f);
    else
        func_0049B208(0);
}

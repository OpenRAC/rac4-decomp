#include "common.h"

extern s32 D_0039D230[];
extern s32 D_00222B9C;
extern s32 func_L01_00480328(s32);
extern void func_L01_00441A08(void *);
extern void func_L01_00480458(void);
extern void func_00449A28(void *, void (*)(), s32);

void func_L01_004805B0(s32 context)
{
    s32 index = 0;
    s32 *slot = D_0039D230;

    do {
        if (func_L01_00480328(index) == 0)
            func_L01_00441A08((void *)*slot);
        index++;
        slot++;
    } while (index < 0x19);

    func_00449A28(&D_00222B9C, func_L01_00480458, context);
}

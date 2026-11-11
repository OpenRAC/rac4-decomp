#include "common.h"

s32 func_L01_0056E6F0(void *object);
void func_L01_005A1B38(void *object);

void func_L01_004E3640(void *object)
{
    u8 *linked = *(u8 **)((u8 *)object + 0xAC);

    if (linked[0x458] != 0) {
        *(s32 *)(linked + 0x340) = func_L01_0056E6F0(object);
    }

    func_L01_005A1B38(object);
}

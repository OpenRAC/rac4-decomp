#include "common.h"

typedef union Setting {
    struct {
        u8 pad[4];
        u8 value, mirror;
    } bytes;
    struct {
        u8 pad[4];
        u16 value;
    } half;
} Setting;
extern Setting D_00171D38[];
extern s32 *D_0021DDA4;
extern s32 func_004B5D68(s32 player);
void func_004B79F8(void)
{
    s32 i;
    D_00171D38[0].bytes.mirror = D_00171D38[0].half.value == 0;
    D_00171D38[0].bytes.value = D_00171D38[0].bytes.mirror;
    for (i = 0; i < *D_0021DDA4; i++)
        func_004B5D68(i);
}

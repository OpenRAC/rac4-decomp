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
extern Setting D_00171DB8[];
extern s32 *D_0021DE2C;
extern s32 func_004B6C58(s32 player);
void func_004B88E8(void)
{
    s32 i;
    D_00171DB8[0].bytes.mirror = D_00171DB8[0].half.value == 0;
    D_00171DB8[0].bytes.value = D_00171DB8[0].bytes.mirror;
    for (i = 0; i < *D_0021DE2C; i++)
        func_004B6C58(i);
}

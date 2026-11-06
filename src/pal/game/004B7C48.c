#include "common.h"

extern u8 D_003099F0[];
extern u8 D_001F8878[];
extern s32 D_0021DE98;
extern s32 func_00506BB8(void);
extern s32 func_004A0F40(s32);
extern void func_0049BED8(s32, s32);

u8 D_0021F888 = 0x01;

void func_004B7C48(void)
{
    s32 index;
    s32 result;
    s32 flag;
    s32 value;

    index = func_00506BB8();
    result = func_004A0F40(index);
    flag = 0;
    D_0021F888 = 0;
    *(s32 *)(D_003099F0 + index * 0x1F8) = result;
    value = D_001F8878[0x69];
    if (value > 0) {
        flag = D_001F8878[0x1C5] != 0;
    }
    if ((D_0021DE98 == 1 || D_0021DE98 == 0x15) && flag != 0) {
        func_0049BED8(index, 0xE);
    } else {
        func_0049BED8(index, 2);
    }
}

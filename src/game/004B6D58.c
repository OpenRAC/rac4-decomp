#include "common.h"

extern u8 D_003098F0[];
extern u8 D_001F87F0[];
extern s32 D_0021DE10;
extern s32 func_00505B20(void);
extern s32 func_004A0208(s32);
extern void func_0049B1A0(s32, s32);

u8 D_0021F7E8 = 0x01;

void func_004B6D58(void)
{
    s32 index;
    s32 result;
    s32 flag;
    s32 value;

    index = func_00505B20();
    result = func_004A0208(index);
    flag = 0;
    D_0021F7E8 = 0;
    *(s32 *)(D_003098F0 + index * 0x1F8) = result;
    value = D_001F87F0[0x69];
    if (value > 0) {
        flag = D_001F87F0[0x1C5] != 0;
    }
    if ((D_0021DE10 == 1 || D_0021DE10 == 0x15) && flag != 0) {
        func_0049B1A0(index, 0xE);
    } else {
        func_0049B1A0(index, 2);
    }
}

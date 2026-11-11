#include "common.h"

extern s32 D_0021DE10;

void func_004230F8(const u32 *kind, u32 *first, u32 *second, s32 *flag)
{
    switch (*kind) {
    case 0:
        *first = 0x00325C66;
        *second = 0x004C6C74;
        break;
    case 1:
        *first = 0x00325C66;
        *second = 0x004C6C74;
        *flag = 0;
        break;
    case 2:
        *first = 0x00325C66;
        *second = 0x004C6C74;
        *flag = 1;
        break;
    case 3:
        if (D_0021DE10 == 0x29 || D_0021DE10 == 0x33 || D_0021DE10 == 0x30) {
            *first = 0x00F0EBEE;
            *second = 0x00F0EBEE;
        } else {
            *first = 0x005786AE;
            *second = 0x002E475C;
        }
        *flag = 0;
        break;
    case 4:
        if (D_0021DE10 == 0x29 || D_0021DE10 == 0x33 || D_0021DE10 == 0x30) {
            *first = 0x00312B2A;
            *second = 0x00312B2A;
        } else {
            *first = 0x0015212B;
            *second = 0x00192834;
        }
        *flag = 0;
        break;
    }
}

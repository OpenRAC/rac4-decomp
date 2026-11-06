/* cflags: -Wuninitialized */
#include "common.h"

s32 func_004983E8(s32 arg0);
s32 func_0049B208(s32 arg0);
void func_004D1DA0(s32 arg0);
void func_L00_00659D48(void);
s32 func_00505B20(void);

void func_L00_00659CB8(void) {
    s32 enabled;
    s32 selection;
    s32 mode;

    enabled = 0;
    selection = func_00505B20();
    mode = func_004983E8(6);
    switch (mode) {
    case 2:
        func_0049B208(selection);
        break;
    case 5:
        enabled = 1;
    case 6:
        func_004D1DA0(enabled);
        break;
    case 13:
        func_L00_00659D48();
        break;
    case 1: case 3: case 4: case 7: case 8: case 9: case 10: case 11: case 12: default:
        return;
    }
}

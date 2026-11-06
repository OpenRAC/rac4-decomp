/* cflags: -Wuninitialized */
#include "common.h"

s32 func_00499120(s32 arg0);
s32 func_0049BF40(s32 arg0);
void func_004CFDB8(s32 arg0);
void func_004CFEE0(void);
s32 func_00506BB8(void);

void func_L00_0065A198(void) {
    s32 enabled;
    s32 selection;
    s32 mode;

    enabled = 0;
    selection = func_00506BB8();
    mode = func_00499120(6);
    switch (mode) {
    case 2:
        func_0049BF40(selection);
        break;
    case 5:
        enabled = 1;
    case 6:
        func_004CFDB8(enabled);
        break;
    case 13:
        func_004CFEE0();
        break;
    case 1: case 3: case 4: case 7: case 8: case 9: case 10: case 11: case 12: default:
        return;
    }
}

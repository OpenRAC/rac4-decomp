#include "common.h"

/* Maps arg0 in 0..4 to a value through a jump table (9, 5, 6, 7, 8) and returns 10 for any other argument. */
s32 func_004CCE70(s32 arg0) {
    s32 var;

    var = 0xA;
    switch (arg0) {
    case 0:
        var = 0x9;
        break;
    case 1:
        var = 0x5;
        break;
    case 2:
        var = 0x6;
        break;
    case 3:
        var = 0x7;
        break;
    case 4:
        var = 0x8;
        break;
    }
    return var;
}

/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01EA20C0(s32 *out, s32 code) {
    if (out == 0) {
        return 0x17;
    }
    switch (code) {
    case 0:
        *out = 0;
        break;
    case 2:
        *out = 2;
        break;
    case 3:
        *out = 3;
        break;
    case 4:
        *out = 4;
        break;
    case 5:
        *out = 5;
        break;
    case 6:
        *out = 6;
        break;
    case 7:
        *out = 7;
        break;
    case 8:
        *out = 8;
        break;
    case 9:
        *out = 9;
        break;
    case 1:
        *out = 1;
        break;
    default:
        return 0x17;
    }
    return 0;
}

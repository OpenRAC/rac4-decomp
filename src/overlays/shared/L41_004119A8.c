#include "common.h"

/* Map the admitted codes to their result value, or return -1. */
s32 func_L41_004119A8(s32 arg0)
{
    int result;

    result = -1;
    switch (arg0) {
    case 0x1ABA: result = 7; break;
    case 0x1ABD: result = 3; break;
    case 0x1ABC: result = 5; break;
    case 0x1ABB: result = 4; break;
    case 0x1B09: result = 0x11; break;
    }
    return result;
}

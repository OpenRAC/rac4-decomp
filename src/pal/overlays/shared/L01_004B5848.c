#include "common.h"

s64 func_L01_004B5848(int arg0)
{
    s64 result;
    int matches;

    result = 0;
    if (*(u8 *)((u8 *)arg0 + 0x69) == 9) {
        matches = *(u8 *)((u8 *)arg0 + 0x20) == 0x1A;
        result = matches;
    }
    return result;
}

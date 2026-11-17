#include "common.h"

s64 func_L01_004B9EC0(int arg0)
{
    s64 result;
    int matches;

    result = 0;
    if (*(u8 *)((u8 *)arg0 + 0x69) == 0x0A) {
        matches = *(u8 *)((u8 *)arg0 + 0x20) == 0x25;
        result = matches;
    }
    return result;
}

#include "common.h"

s64 func_L01_0045D380(void *object)
{
    s64 result;
    int matches;

    result = 0;
    if (*(u8 *)((u8 *)object + 0x69) == 7) {
        matches = *(u8 *)((u8 *)object + 0x20) == 0x1B;
        result = matches;
    }
    return result;
}

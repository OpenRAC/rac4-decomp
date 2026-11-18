/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s64 func_L01_0046AB60(void *arg0)
{
    s64 result = 0;
    if ((*((u8 *) (((u8 *) arg0) + 0x69))) == 7) {
        int matches = (*((u8 *) (((u8 *) arg0) + 0x20))) == 0x1A;
        result = matches;
    }
    return result;
}

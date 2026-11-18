/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s64 func_L05_00494290(void *arg0)
{
    s64 result = 0;
    if ((*((u8 *) (((u8 *) (*((void **) (((u8 *) arg0) + 0xAC)))) + 424))) == 0) {
        int matches = (*((u8 *) (((u8 *) arg0) + 0x20))) == 7;
        result = matches;
    }
    return result;
}

/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s64 func_L10_004D6DB8(void *arg0)
{
    s64 result = 0;
    if ((*((u8 *) (((u8 *) (*((void **) (((u8 *) arg0) + 0xAC)))) + 1016))) == 0) {
        int matches = (*((u8 *) (((u8 *) arg0) + 0x20))) == 1;
        result = matches;
    }
    return result;
}

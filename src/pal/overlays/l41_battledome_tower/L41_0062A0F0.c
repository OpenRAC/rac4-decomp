/* cflags: -Wuninitialized */
#include "common.h"

extern u8 D_0036E150[];

/* Clear ten consecutive 16-byte records. */
void func_L41_0062A0F0(void)
{
    s32 count = 9;
    u8 *record = D_0036E150;

    do {
        *(s32 *)(record + 0) = 0;
        count -= 1;
        *(s32 *)(record + 4) = 0;
        *(s32 *)(record + 8) = 0;
        *(s32 *)(record + 12) = 0;
        record += 16;
    } while (count >= 0);
}

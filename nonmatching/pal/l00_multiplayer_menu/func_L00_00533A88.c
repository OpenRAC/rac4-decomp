/* Not matching yet: 11/13 (84.62%) relocation-masked positional words; 52/52 candidate/target bytes. Delay-slot scheduling differs; nonnegative count and valid buffers are assumed. Reproduce: python tools/check_func.py --version pal func_L00_00533A88 nonmatching/pal/l00_multiplayer_menu/func_L00_00533A88.c --diff. Not part of the build. */
/* cflags: @ee29 -O1 -G0 -Wuninitialized */
#include "common.h"

/* Copy count bytes forward and return the original destination. */
u8 *func_L00_00533A88(u8 *destination, const u8 *source, s32 count)
{
    u8 *result = destination;
    s32 remaining = count - 1;
    if (count != 0) {
        do {
            u8 value = *source++;
            remaining--;
            *destination++ = value;
        } while (remaining != -1);
    }
    return result;
}

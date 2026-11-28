/* cflags: @ee296 -O2 -G0 */
#include "common.h"

/* Copy bytes forward and return the initial destination. */
u8 *func_L00_00533A88(u8 *destination, const u8 *source, u32 count)
{
    u8 *result = destination;
    u32 remaining = count - 1;
    if (count != 0) {
        do {
            u8 value = *source++;
            remaining--;
            *destination = value;
            destination++;
        } while (remaining != (u32)-1);
    }
    return result;
}

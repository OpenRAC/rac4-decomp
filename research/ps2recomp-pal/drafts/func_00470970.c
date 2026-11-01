/* cflags: -O1 */
/* Unmatched PAL reconstruction; excluded from the build and progress counts.
 * See notes/pal-00470970.md. The return type models the observed v0 value;
 * it is not a confirmed original source-level prototype.
 */
#include "common.h"

u64 func_00470970(void *object, u64 high, u64 low, u64 byte1, u64 byte2)
{
    u64 result = low;

    high <<= 32;
    byte1 <<= 8;
    byte2 <<= 16;
    result = high | result;
    result |= byte1;
    result |= byte2;
    *(u64 *)((u8 *)object + 0x38) = result;
    return result;
}

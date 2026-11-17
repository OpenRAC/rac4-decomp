/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s16 func_L00_004F1738(s32);

// Fill two 16-bit fields of the object at +0 and +2 from func_L00_004F1738 and return 4.
s32 func_L00_004EFEC8(void *arg0) {
    *(s16 *)((char *)arg0 + 0x0) = func_L00_004F1738(2);
    *(s16 *)((char *)arg0 + 0x2) = func_L00_004F1738(5);
    return 4;
}

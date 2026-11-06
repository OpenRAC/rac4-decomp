/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_00403308(void *, s32, u32);
// Clears 0xC bytes and returns the destination.
void *func_003FE7D0(void *p) {
    return func_00403308(p, 0, 0xC);
}

/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *, s32, u32);
// Clears 0x40 bytes and returns the destination.
void *func_01F07154(void *p) {
    return func_0011A518(p, 0, 0x40);
}

/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_001B7678[];
extern void *func_0011A370(void *, const void *, u32);
// Copies the fixed 24-byte record to the destination.
void *func_01ED5570(void *p) {
    return func_0011A370(p, D_001B7678, 0x18);
}

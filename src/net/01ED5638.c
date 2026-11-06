/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_001B7690[];
extern void *func_0011A370(void *, const void *, u32);
// Copies the fixed 48-byte record to the destination.
void *func_01ED5638(void *p) {
    return func_0011A370(p, D_001B7690, 0x30);
}

/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_001B7678[];
extern void *func_0011A370(void *, const void *, u32);
// Copies the source record to the fixed destination.
void *func_01ED5548(const void *p) {
    return func_0011A370(D_001B7678, p, 0x18);
}

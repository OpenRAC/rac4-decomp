/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

extern void func_01EFA118(void *, s8, s32);
// Forwards the signed byte and a zero flag to the object helper.
void func_01EFA2A4(void *p, s8 value) {
    func_01EFA118(p, value, 0);
}

/* cflags: @ee296 -O2 -G0 */
#include "common.h"
/* Not matching yet: BYTES 8/60 (tools/try_func.py func_01EA88C8 --diff). Not part of the build. */
/* Calls func_01EA9550 with the address of a local slot and 0x24; if the slot came back non-NULL, writes 1 through it and returns it, else NULL. */
extern void func_01EA9550(void *, s32);

s32 *func_01EA88C8(void) {
    s32 *p = NULL;

    func_01EA9550(&p, 0x24);
    if (p != NULL) {
        *p = 1;
        return p;
    }
    return NULL;
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 open;
    u8 pad14[0x1C - 0x14];
} Type1;
extern Type1 D_1AF010[2][4];
extern void *func_0013B8C8(s32 arg0, s32 arg1, void *out);

// Calls func_0013B8C8 for an open slot and returns 1 when its status bytes say so.
s32 func_0013C190(s32 port, s32 slot) {
    u8 out[0x80];

    if (D_1AF010[port][slot].open != 0) {
        func_0013B8C8(port, slot, out);
        if (out[0x72] == 1) {
            goto ok;
        }
    }
fail:
    return 0;
ok:
    if (out[0x64] < 2) {
        goto fail;
    }
    if ((out[0x66] & 2) == 0) {
        goto fail;
    }
    return 1;
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"

/* Allocates a 0x14-byte record, clears it, stores a call's result in it and returns it; NULL on failure. */
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8(s32);
extern s32 func_L00_00536270(void);

void *func_L00_00536998(void) {
    s32 err[12];
    s32 *p;
    s32 r;

    p = func_L00_004FACD8(0x14);
    if (p == 0) {
        err[11] = 0xEE;
        goto fail;
    }
    p[0] = 0;
    p[1] = 0;
    p[3] = 0;
    r = func_L00_00536270();
    p[2] = r;
    return (r != 0) ? p : 0;
fail:
    func_L00_004F84C8(0xD, 0xD3, 0x21, 0, 0);
    return 0;
}

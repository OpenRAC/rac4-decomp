/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern char *func_0011AFC8(char *, char *, s32);
extern s32 D_004885AC[];
extern u8 D_004885B0[];

/* Copies the stored name and value to the caller's buffers; -11 for bad arguments, -8 when not ready. */
s32 func_L00_004EFE20(s32 *out0, char *buf, s32 count, u16 *out1)
{
    u8 *state;
    if (buf == NULL || out1 == NULL || count <= 0) {
        return -0xB;
    }
    if (D_004885AC[0] == 0) {
        return -8;
    }
    state = D_004885B0;
    if (*(s32 *)(state + 0x404) != 0) {
        *out0 = *(s32 *)(state + 0x404);
        func_0011AFC8(buf, state + 0x204, count);
        *out1 = *(u16 *)(state + 0x408);
    } else {
        *out0 = 0;
    }
    return 0;
}

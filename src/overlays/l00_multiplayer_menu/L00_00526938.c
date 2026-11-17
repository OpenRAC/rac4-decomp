/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_L00_004FACD8(s32);
extern void *func_L00_00520488(void *a1, void *a2, int a3);
extern void func_L00_00526210(void *arg0);
extern void *func_L00_005417D0(void *arg0);

// Creates the entry for arg0's key, copies arg0's 12-byte payload into it, and frees the entry on failure.
s32 *func_L00_00526938(s32 *arg0) {
    s32 *s0;
    s32 *temp;

    s0 = (s32 *)func_L00_005417D0((void *)arg0[2]);
    if (s0 == 0) {
        return 0;
    }
    if (func_L00_00520488((void *)s0[1], (void *)arg0[1], 0x12) == 0) {
        goto block_5;
    }
    if (arg0[6] != 0) {
        temp = func_L00_004FACD8(0xC);
        s0[6] = (s32)temp;
        if (temp == 0) {
            goto block_5;
        }
        temp[0] = ((s32 *)arg0[6])[0];
        ((s32 *)s0[6])[1] = ((s32 *)arg0[6])[1];
        ((s32 *)s0[6])[2] = ((s32 *)arg0[6])[2];
    }
    return s0;
block_5:
    if (s0 != 0) {
        func_L00_00526210(s0);
    }
    return 0;
}

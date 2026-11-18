/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct { char b[2032]; } Blob1;
extern void *func_01EEFEB8();
extern void func_01F0C090(char *arg0, s32 arg1);
extern u8 D_0019B870[];

/* copies a 2032-byte block from arg1 into the object looked up from arg0 */
s32 func_01EEB6E0(char *arg0, char *arg1) {
    Blob1 *src = (Blob1 *)(arg1 + 0x1388);
    Blob1 *dst = func_01EEFEB8(*(s32 *)(arg0 + 0x138));
    if (dst == 0) {
        func_01F0C090(D_0019B870, 0x44A);
    }
    *dst = *src;
    return 1;
}

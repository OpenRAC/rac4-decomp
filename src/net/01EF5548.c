/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA7538(void);
extern s32 func_01EA7EC8(void *o, s32 *out);
extern void func_01EED528(s32 a0);
extern void func_01F0C090(char *arg0, s32 arg1);
extern char D_0019C8C0[];

/* Check a state pair and report an error when it is inconsistent. */
s32 func_01EF5548(u8 *a0) {
    s32 out;
    s32 r;
    s32 k;

    if (func_01EA7538() == 0) {
        r = func_01EA7EC8(*(void **)(a0 + 0xC), &out);
        k = out;
        if (k == 1 && r == 0) {
            return 1;
        }
        if (k != 0 || r != 0) {
            if (r != 0) {
                func_01EED528(0x26);
            } else {
                func_01EED528(0x26);
                func_01F0C090(D_0019C8C0, 0x1CA);
            }
        }
    }
    return 0;
}

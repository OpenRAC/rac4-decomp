/* cflags: -O2 -G8 -malign-jumps=4 */
#include "common.h"

extern s32 func_01EA95C0(s32 *arg0);

typedef struct {
    s32 f0;
    s32 f4;
} S;

s32 func_01EDAC88(S *arg0) {
    S *p = arg0;
    if (p != 0 && p->f4 != 0) {
        p->f4 = 0;
        return func_01EA95C0((s32 *)&arg0) ? -0x15 : 0;
    }
    return -0x15;
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    unsigned long *f0;
    s32 f4;
    s32 f8;
} Type1;
extern int func_L00_005382C8(int a1, int a2);
extern unsigned long func_L00_00539898(unsigned long *rp, unsigned long *ap, int num, unsigned long w);

// Appends the product word of the array to it, growing through func_L00_005382C8; returns 0 when growing fails.
s32 func_L00_00539488(Type1 *arg0, unsigned long arg1) {
    unsigned long v;

    if (arg0->f4 == 0) {
        return 1;
    }
    v = func_L00_00539898(arg0->f0, arg0->f0, arg0->f4, arg1);
    if (v != 0) {
        if (arg0->f8 < arg0->f4 + 1 && func_L00_005382C8((int)arg0, arg0->f4 + 1) == 0) {
            return 0;
        }
        arg0->f0[arg0->f4++] = v;
    }
    return 1;
}

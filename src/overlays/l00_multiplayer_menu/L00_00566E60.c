/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Node_566C80 {
    struct Node_566C80 *f0;
    s32 f4;
    s32 f8;
    u8 pad[0x48];
    struct Node_566C80 *f54;
    s32 f58;
    struct Node_566C80 *f5C;
} Node_566C80;

extern Node_566C80 *D_004A9BA0[];

// Counts leading ids 0, 1, 2... for which some node (or one of its two sublists) has that id in f8.
s32 func_L00_00566E60(void) {
    s32 n = 0;
    Node_566C80 *p;
    Node_566C80 *q;

    for (;;) {
        for (p = D_004A9BA0[0]; p != 0; p = p->f0) {
            if (n == p->f8) {
                break;
            }
            for (q = p->f54; q != 0; q = q->f0) {
                if (n == q->f8) {
                    break;
                }
            }
            if (q != 0) {
                break;
            }
            for (q = p->f5C; q != 0; q = q->f0) {
                if (n == q->f8) {
                    break;
                }
            }
            if (q != 0) {
                break;
            }
        }
        if (p == 0) {
            break;
        }
        n++;
    }
    return n;
}

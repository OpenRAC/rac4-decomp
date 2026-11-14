/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_004FAD28(s32);
extern void *func_L00_004FACD8();

/* Allocates a 0x14-byte node bound to arg0, runs arg0's init callback, and frees it on failure */
s32 *func_L00_00541B60(s32 *arg0) {
    s32 *node;
    s32 (*init)(s32 *);

    node = func_L00_004FACD8(0x14);
    if (node == 0) {
        return 0;
    }
    node[0] = 0;
    node[1] = 0;
    node[2] = (s32)arg0;
    node[3] = 0;
    node[4] = 0;
    init = (s32 (*)(s32 *))arg0[1];
    if (init != 0 && init(node) == 0) {
        func_004FAD28((s32)node);
        return 0;
    }
    return node;
}

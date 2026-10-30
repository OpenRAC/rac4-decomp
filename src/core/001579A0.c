#include "common.h"

extern s32 D_0021DE10;
extern s32 D_21DA24;
extern char func_01E9A000[];
s32 func_00157738(void *, void *);
void func_00157888(s32);
/* Calls func_00157738 on the block at D_21DA24, then func_00157888 on D_0021DE10, and returns the first result. */
s32 func_001579A0(void) {
    s32 temp_s0;
    s32 p;

    p = D_21DA24;
    temp_s0 = func_00157738((void *)(*(s32 *)(p + 8) + p), func_01E9A000);
    func_00157888(D_0021DE10);
    return temp_s0;
}

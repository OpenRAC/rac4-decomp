/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern u8 D_00195418[];
extern void func_00146638(s32, void *);

/* from rac3-decomp's func_001347D0 */
void func_00140D10(s32 arg0) {
    func_00146638(arg0, D_00195418);
}

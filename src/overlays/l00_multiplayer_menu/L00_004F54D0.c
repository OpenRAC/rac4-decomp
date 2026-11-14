/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A9EC(void *, void *);
extern s32 D_00466090[];
extern u16 D_00466290[];
extern s32 D_00498D70[];

/* Records a pending flag, hands arg0 to func_0011A9EC and stores the low 16 bits of arg1. */
s32 func_L00_004F54D0(void *arg0, s32 arg1) {
    u16 v = arg1;
    D_00498D70[0] = 1;
    func_0011A9EC(D_00466090, arg0);
    D_00466290[0] = v;
    return 0;
}

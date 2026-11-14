#include "common.h"

/* passes a buffer and the global values to func_0011D920, then hands a 3-word block to func_L00_00709AC8 */
extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern void func_L00_00709AC8(void *arg0);
extern s8 D_00221170[];
extern s32 D_00223404;

void func_L00_0073D990(s32 arg0, s32 arg1, s32 arg2) {
    struct {
        s32 sp[3];
        s8 pad[15];
        s8 buf[0x185];
    } f;

    f.sp[0] = D_00223404;
    f.sp[1] = 1;
    func_0011D920(f.buf, D_00221170, arg1, arg2);
    f.sp[2] = arg0;
    func_L00_00709AC8(f.sp);
}

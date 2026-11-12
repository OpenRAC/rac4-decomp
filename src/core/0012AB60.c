/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 D_00164730;
extern u8 D_001A9040[];
extern void func_0012A970(void);
extern s32 func_00126BE0(s32);
extern s32 func_00126BC0(s32);

void *func_0012AB60(u32 arg0) {
    void *ret;

    func_0012A970();
    func_00126BE0(D_00164730);
    if (arg0 >= 0x20U) {
        func_00126BC0(D_00164730);
        return NULL;
    }
    ret = D_001A9040 + arg0 * 16;
    func_00126BC0(D_00164730);
    return ret;
}

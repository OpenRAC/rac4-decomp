/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169D30;
extern s32 D_00169D50;
extern s32 func_01E9E630(s32 *);
extern s32 func_01ED5778(void);
extern void func_01ED4438(void);
extern s32 func_01E9E798(void);
s32 func_01ED6098(void) {
    s32 t = 0;
    s32 r;
    func_01E9E630(&t);
    if (D_00169CD0 != 1) {
        return -0xF;
    }
    r = func_01ED5778();
    if (r != 0) {
        return r;
    }
    if (D_00169D50 == 1) {
        func_01ED4438();
    }
    r = func_01E9E798();
    if (r == 0) {
        return 0;
    }
    D_00169D30 = r;
    return -0xA;
}

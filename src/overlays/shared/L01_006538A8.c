/* cflags: -G0 */
#include "common.h"

extern u8 D_001711BD;
extern s32 func_L00_00696490(s32, s32);
extern void func_L01_00653428(void);
extern void func_L01_00653520(void);

void func_L01_006538A8(s32 arg0, s32 arg1) {
    if (D_001711BD != 0) {
        if (arg1 != 0) {
            func_L00_00696490(arg0, 1);
            return;
        }
        func_L01_00653520();
        return;
    }
    func_L01_00653428();
}

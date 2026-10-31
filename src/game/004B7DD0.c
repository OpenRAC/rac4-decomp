#include "common.h"

extern void func_00497980(s32 arg0);
extern s32 func_004B7BC0(s32 index);
extern void func_00501498(s32 *arg0);
extern s32 func_00505AD8(s32 a);
extern s32 func_00505B20(void);
extern void func_00505C90(s32);
extern s32 D_0021F840;

// Re-runs the setup calls on arg0 and on the value from func_00505B20, sets flag D_0021F840 to 2, then calls func_00497980 with 0xB.
void func_004B7DD0(s32 arg0) {
    s32 temp_s1;

    temp_s1 = func_00505B20();
    func_00505AD8(arg0);
    func_00501498(func_004B7BC0(arg0));
    func_00505C90(func_004B7BC0(arg0));
    func_00505AD8(temp_s1);
    D_0021F840 = 2;
    func_00497980(0xB);
}

#include "common.h"

extern s32 func_004C94F8(s32 index);
extern void func_00501498(s32 *arg0);
extern s32 func_00505AD8(s32 a);
extern s32 func_00505B20(void);
extern void func_00505C90(s32);
s32 D_0021FA28 = 0;
// Calls the func_00505B20 / func_004C94F8 chain and the func_00505AD8 / func_00505C90 calls for arg0, then sets D_0021FA28 to 1.
void func_004C9728(s32 arg0) {
    s32 temp_s1;

    temp_s1 = func_00505B20();
    func_00505AD8(arg0);
    func_00501498((s32 *)func_004C94F8(arg0));
    func_00505C90(func_004C94F8(arg0));
    func_00505AD8(temp_s1);
    D_0021FA28 = 1;
}

/* cflags: @ee29 -O2 -G8 */
#include "common.h"



s32 func_004A1A78();
void func_00501498(s32);
s32 func_00505C90(s32);
extern s32 D_0021F658;
extern s32 D_0021F65C;


s32 func_004A1AE0(void) {
    s32 result;
    func_00501498(func_004A1A78());
    result = func_00505C90(func_004A1A78());
    D_0021F65C = 0;
    D_0021F658 = 1;
    return result;
}

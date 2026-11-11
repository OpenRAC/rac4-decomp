/* cflags: -O2 -G8 -Wa,-G0 */
#include "common.h"

s32 func_004F2728(s32, s32);
s32 func_004F3220(s32, s32);
s32 func_004F4F70(s32);
s32 func_004F5530(void *);
void func_004F62E0(void);
extern s8 D_00221F48[2];

s32 func_004F6288(void) {
    D_00221F48[0] = 0;
    D_00221F48[1] = 0;
    func_004F2728(1, 0);
    func_004F4F70(0);
    func_004F5530(func_004F62E0);
    func_004F3220(7, 0);
    return 1;
}

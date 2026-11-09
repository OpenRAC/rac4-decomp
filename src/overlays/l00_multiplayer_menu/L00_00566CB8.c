/* cflags: @ee29 */
#include "common.h"

extern s32 func_0011A518(void *, s32, s32);
extern s32 func_005664A8(s32);

void func_L00_00566CB8(u8 *arg0, s32 *arg1) {
    func_0011A518(arg0, 0, 0x10);
    *(s32 *)(arg0 + 4) = func_005664A8(*arg1);
}

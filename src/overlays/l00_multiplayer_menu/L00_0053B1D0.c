/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011A518(void *, s32, s32);
extern void *func_L00_004FACD8(s32);
extern void func_L00_00538D98(void *);
s32 func_L00_0053B1D0(s32 arg0, s32 *arg1) {
    u8 *object = func_L00_004FACD8(0x78);
    u8 *temp;
    if (object == 0) return 1;
    func_0011A518(object, 0, 0x20);
    temp = object + 0x20;
    *(s32 *)(object + 0) = arg0;
    *(u8 **)(object + 0x10) = temp;
    func_L00_00538D98(temp);
    *(s32 *)(object + 0x14) = 0;
    *(s32 *)(object + 0x18) = 0;
    *arg1 = (s32)object;
    return 0;
}

/* cflags: @lit4 */
#include "common.h"

extern void func_L00_005DE048(void *, s32, void *);
extern void *func_L05_0040C548(void *, s32, void *, s32, s32, s32, s32, f32);
extern u8 *D_0021DFF0;

// Toggle the linked object's +0x248 flag around a spawn through func_L05_0040C548; store arg5 at +0x90 of the result.
void func_L41_003BEE28(void *obj, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5) {
    u32 buf[4];
    u8 *linked = *(u8 **)((u8 *)obj + 0xAC);
    u8 *result;
    *(s32 *)(linked + 0x248) = arg3;
    func_L00_005DE048(obj, arg3 + 2, buf);
    result = func_L05_0040C548(obj, arg1, buf, 0x801, arg2, 1, *(s8 *)(D_0021DFF0 + 0x22) ? arg4 : 0, 0.05f);
    if (result != 0 && arg5 != 0xFFFFFFFF) *(s32 *)(result + 0x90) = arg5;
    *(s32 *)(linked + 0x248) ^= 1;
}

/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern s32 func_0011A518(void *, s32, s32);
extern void func_L00_0051B938(void *);
extern void func_L00_0051B988(void *, s32, s32);
extern void func_L00_0051BEC8(void *, void *);
extern u8 D_00477188[];
u8 *func_L00_00541000(s32 arg0, s32 arg1, u8 *arg2) {
    u8 *result = arg2;
    u8 frame[0x5C];
    if (result == 0) result = D_00477188;
    func_L00_0051B938(frame);
    func_L00_0051B988(frame, arg0, arg1);
    func_L00_0051BEC8(result, frame);
    func_0011A518(frame, 0, 0x5C);
    return result;
}

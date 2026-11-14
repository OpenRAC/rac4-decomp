/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_L00_00553488(void *arg0, s32 arg1, s32 arg2, s32 arg3);

/* clears the object, inits its sub-object, stores a value */
void func_L00_005522A8(void *arg0, s32 arg1) {
    func_0011A518(arg0, 0, 0xE8);
    func_L00_00553488((u8 *)arg0 + 8, 0, 0, 0);
    *(s32 *)arg0 = arg1;
}

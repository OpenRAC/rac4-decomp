/* Not matching yet: BYTES 14/168 (tools/try_func.py func_L08_003E74D0 --diff). Not part of the build. */
/* cflags: -O2 -G8 */
#include "common.h"

extern s32 func_L00_005E60D0(s32, s32);
extern void func_L00_005E7538(void *, s32, f32);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

s32 func_L08_003E74D0(u8 *arg0) {
    s32 temp_a0;
    s32 *temp_v1;

    temp_v1 = *(s32 **)(arg0 + 0xAC);
    if (*(u8 *)(arg0 + 0x20) != 0) {
        return 0;
    }
    if ((temp_v1[0] != -1) || (temp_v1[1] != -1)) {
        temp_a0 = temp_v1[2];
        if (temp_a0 != -1) {
            goto state1;
        }
        if (temp_v1[3] != (s32) arg0) {
            goto state1;
        }
    }
    func_L00_005E7538(arg0, 0, (f32) func_L00_005E60D0(0, 0x19));
    func_L01_00591BD8(arg0, 4, -1);
    return 1;
state1:
    func_L01_00591BD8(arg0, 1, -1);
    return 1;
}

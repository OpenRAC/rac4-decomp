/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_00516C48(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);

/* Unlinks arg0 from its list neighbours, clears its links, calls func_L00_00516C48 on it, and returns the old next pointer. */
void *func_L00_00516DC0(void *arg0) {
    void *temp_s0;
    void *temp_v0;
    void *temp_a0;

    if (arg0 == 0) {
        return 0;
    }
    temp_s0 = *(void **)((u8 *)arg0 + 0x24);
    temp_v0 = *(void **)((u8 *)arg0 + 0x28);
    temp_a0 = temp_s0;
    if (temp_v0 != 0) {
        *(void **)((u8 *)temp_v0 + 0x24) = temp_s0;
        temp_a0 = *(void **)((u8 *)arg0 + 0x24);
    }
    if (temp_a0 != 0) {
        *(void **)((u8 *)temp_a0 + 0x28) = *(void **)((u8 *)arg0 + 0x28);
    }
    *(void **)((u8 *)arg0 + 0x24) = 0;
    *(void **)((u8 *)arg0 + 0x28) = 0;
    func_L00_00516C48((s32)arg0, 7, 0, 0);
    return temp_s0;
}

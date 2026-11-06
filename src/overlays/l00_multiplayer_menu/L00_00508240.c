/* cflags: @ee29 */
#include "common.h"
s32 func_0011A518();
void func_L00_00508240(void *arg0) {
    s32 temp_a2;

    if (arg0 != NULL) {
        temp_a2 = (*(s32 *)((u8 *)(arg0) + 0));
        if (temp_a2 > 0) {
            func_0011A518((*(s32 *)((u8 *)(arg0) + 4)), 0, temp_a2 * 4);
            (*(s32 *)((u8 *)(arg0) + 0)) = 0;
        }
    }
}

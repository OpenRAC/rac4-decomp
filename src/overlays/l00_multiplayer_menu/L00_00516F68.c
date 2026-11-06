/* cflags: @ee29 */
#include "common.h"
s32 func_0011A518();
s32 func_L00_004FAD28(void *);                  /* extern */

void func_L00_00516F68(void *arg0) {
    void *temp_a0;

    if (arg0 != NULL) {
        temp_a0 = (*(void **)((u8 *)(arg0) + 4));
        if (temp_a0 != NULL) {
            func_0011A518(temp_a0, 0, (*(s32 *)((u8 *)(arg0) + 8)));
            func_L00_004FAD28((*(void **)((u8 *)(arg0) + 4)));
        }
        func_L00_004FAD28(arg0);
    }
}

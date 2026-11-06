/* cflags: @ee29 */
#include "common.h"
s32 func_L00_005168B0(void *);                  /* extern */

void func_L00_00516E40(void *arg0) {
    s32 temp_s0;
    void *temp_a0;

    while (arg0 != NULL) {
        temp_a0 = arg0;
        temp_s0 = (*(s32 *)((u8 *)(arg0) + 0x2C));
        arg0 = (*(void **)((u8 *)(arg0) + 0x24));
        func_L00_005168B0(temp_a0);
        if (temp_s0 >= 2) {
            break;
        }
    }
}

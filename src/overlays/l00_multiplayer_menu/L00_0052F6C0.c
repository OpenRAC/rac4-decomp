/* cflags: @ee29 */
#include "common.h"
s32 func_L00_004FAD28(void *);                  /* extern */
s32 func_L00_00535898(s32);                     /* extern */
s32 func_L00_005362F8(s32);                     /* extern */

void func_L00_0052F6C0(void *arg0) {
    s32 (*temp_v0)();

    if (arg0 != NULL) {
        if ((*(s32 *)((u8 *)(arg0) + 0x18)) != 0) {
            temp_v0 = (*(s32 (**)())((u8 *)(arg0) + 0x1C));
            if (temp_v0 != NULL) {
                temp_v0();
            }
        }
        func_L00_00535898((*(s32 *)((u8 *)(arg0) + 0)));
        func_L00_005362F8((*(s32 *)((u8 *)(arg0) + 8)));
        func_L00_004FAD28(arg0);
    }
}

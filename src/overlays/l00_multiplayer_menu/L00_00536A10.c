/* cflags: @ee29 */
#include "common.h"
s32 func_L00_004FAD28(void *);                  /* extern */
s32 func_L00_005362F8(s32);                     /* extern */
s32 func_L00_00535898(s32);                     /* extern */

void func_L00_00536A10(void *arg0) {
    if (arg0 != NULL) {
        func_L00_00535898((*(s32 *)((u8 *)(arg0) + 4)));
        func_L00_005362F8((*(s32 *)((u8 *)(arg0) + 8)));
        func_L00_004FAD28(arg0);
    }
}

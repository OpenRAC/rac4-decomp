/* cflags: @ee29 */
#include "common.h"
s32 func_L00_00538180(void *);                  /* extern */

void func_L00_00538D98(void *arg0) {
    (*(s32 *)((u8 *)(arg0) + 0)) = 0;
    (*(s32 *)((u8 *)(arg0) + 8)) = 0;
    func_L00_00538180(arg0 + 0xC);
    func_L00_00538180(arg0 + 0x20);
    func_L00_00538180(arg0 + 0x34);
    (*(s32 *)((u8 *)(arg0) + 0x50)) = 0;
}

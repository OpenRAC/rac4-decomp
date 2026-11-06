/* cflags: @ee29 */
#include "common.h"
s32 func_L00_004FAD28(void *);                  /* extern */
s32 func_L00_00537FB0(s32);                     /* extern */

void func_L00_00538258(void *arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0xB;
    var_s0 = arg0 + 4;
    do {
        var_s1 -= 1;
        func_L00_00537FB0(var_s0);
        var_s0 += 0x14;
    } while (var_s1 >= 0);
    if ((*(s32 *)((u8 *)(arg0) + 0x108)) & 1) {
        func_L00_004FAD28(arg0);
    }
}

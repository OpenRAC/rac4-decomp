/* cflags: @ee29 */
#include "common.h"

s32 func_L00_00508270(s32 *arg0);

s32 func_L00_00508388(s32 *);                       /* extern */

s32 func_L00_005083B0(s32 arg0, s32 *arg1) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    if (arg1 == NULL) {
        return 0;
    }
    temp_v0 = func_L00_00508388(arg1);
    switch (temp_v0) {                              /* switch 1; irregular */
    case 0x6:                                       /* switch 1 */
        var_s0 = 0x31;
        break;
    case 0x74:                                      /* switch 1 */
        var_s0 = 0x12;
        break;
    case 0x1C:                                      /* switch 1 */
        var_s0 = 0x44;
        break;
    }
    switch (arg0) {                                 /* switch 2; irregular */
    case 0x6: var_s0 |= 0x100; break;
    case 0x200: var_s0 |= 0x200; break;
    }
    return (func_L00_00508270(arg1) > 0x200) ? var_s0 : (var_s0 | 0x1000);
}

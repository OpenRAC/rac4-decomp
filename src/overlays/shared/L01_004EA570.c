/* cflags: @ee29 -O2 -G0 */
#include "common.h"




void func_L01_004EA570(s32 ignored, char *arg1) {
    s32 *var_a1;
    s32 var_v1;

    var_a1 = (s32 *)(arg1 + 0x378);
    var_v1 = 5;
    do {
        var_v1 -= 1;
        if (*var_a1 != 0) {
            *var_a1 = 0;
        }
        var_a1++;
    } while (var_v1 >= 0);
}

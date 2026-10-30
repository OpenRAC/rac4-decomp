#include "common.h"

/* Counts the entries of a 256-slot pointer table whose word at 0x20 is set, storing the count in arg0; 0 on success, 0x17 with no output. */
s32 func_01EA0CB0(s32 *arg0, void **arg1) {
    s32 var_v0;
    u32 var_v1;
    void **var_a1;
    void *temp_v0;

    var_a1 = arg1;
    var_v1 = 0;
    var_v0 = 0x17;
    if (arg0 != 0) {
        *arg0 = 0;
        if (var_a1 != 0) {
            do {
                temp_v0 = *var_a1;
                var_a1++;
                if ((temp_v0 != 0) && (*(s32 *)((char *)temp_v0 + 0x20) != 0)) {
                    *arg0 += 1;
                }
                var_v1 += 1;
            } while (var_v1 < 0x100);
            var_v0 = 0;
        }
    }
    return var_v0;
}

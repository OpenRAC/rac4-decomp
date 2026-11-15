#include "common.h"

extern s32 func_00502448(s32 *arg0);
extern char *func_00502738(char *data, u32 *id);

/* Finds the table for arg0, then returns arg0 plus the word func_00502448 reads from its entry, or 0. */
s32 func_005027E0(s32 arg0) {
    u32 id;
    s32 var_s0;
    s32 count;
    s32 found;

    var_s0 = (s32)func_00502738((char *)arg0, &id);
    if (var_s0 != 0) {
        count = func_00502448((s32 *)var_s0);
        var_s0 += 4;
        found = func_00502448((s32 *)(var_s0 + (count << 2)));
        if (found == 0) {
            return 0;
        }
        var_s0 = found + arg0;
    }
    return var_s0;
}

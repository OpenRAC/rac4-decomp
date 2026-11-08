/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xB4];
    s32 fB4;
    char _pB8[0x38];
    s32 fF0;
};

void func_01F030DC(Type1 *arg0) {
    s32 *var_v1;
    s32 var_a1;

    var_a1 = 0;
    if (arg0->fB4 > 0) {
        var_v1 = arg0->fF0;
        do {
            *var_v1 = var_a1;
            var_a1 += 1;
            var_v1 += 1;
        } while (var_a1 < arg0->fB4);
    }
}

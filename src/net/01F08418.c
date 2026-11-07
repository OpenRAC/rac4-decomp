/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

extern s32 D_001B7FE0[];

void func_01F08418(void) {
    void *var_v1;

    if (D_001B7FE0 != NULL) {
        var_v1 = D_001B7FE0 + 0x118;
        if (var_v1 != D_001B7FE0) {
            do {
                var_v1 -= 0x8C;
            } while (var_v1 != D_001B7FE0);
        }
    }
}

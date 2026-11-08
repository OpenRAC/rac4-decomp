/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

s32 func_0011EFB0();
extern s32 (*D_0048840C)();

void func_L00_00566910(void) {
    if (D_0048840C == NULL) {
        func_0011EFB0();
        return;
    }
    D_0048840C();
}

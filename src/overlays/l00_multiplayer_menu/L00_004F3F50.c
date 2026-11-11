/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

s32 func_0012EB98(s32);
extern s32 D_00498D84[];

void func_L00_004F3F50(void) {
    if (D_00498D84[0] >= 0) {
        func_0012EB98(D_00498D84[0]);
        D_00498D84[0] = -1;
    }
}

/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

s32 func_01E9C0B0(void *);
s32 func_01E9C170(void *, void *);
s32 func_01E9D740(void *, void *);
extern s32 D_001694FC[];
extern s32 D_00169508[];
extern s32 D_001B26C0[];
extern s32 D_001B2700[];

void func_01EB4F80(void) {
    func_01E9D740(D_001B26C0, D_001B2700);
    if (func_01E9C170(D_001B26C0, D_001B2700) >= 0) {
        func_01E9C0B0(D_001B26C0);
        D_00169508[0] = -1;
        D_001694FC[0] = 0;
    }
}

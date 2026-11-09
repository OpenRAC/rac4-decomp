/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses */
#include "common.h"

void func_0015DB88(void **);
void func_01F07D64(void **, s32);
extern s32 D_00170EF0[];

void func_01F07E8C(void **arg0, s32 arg1) {
    *arg0 = D_00170EF0;
    func_01F07D64(arg0, 0);
    if (arg1 & 1) {
        func_0015DB88(arg0);
    }
}

/* cflags: @ee296 -O2 -G0 -fno-gcse */
#include "common.h"

s32 func_01EA9BC8(void);
void func_01EB3ED0(void);

void func_01EB3F10(s32 *arg0) {
    u8 i;

    func_01EB3ED0();
    for (i = 0; i < 16; i++) {
        arg0[i] = func_01EA9BC8();
    }
}

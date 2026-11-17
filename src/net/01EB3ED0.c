/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_001694F8;
s32 func_01EA9C80(s32);
void func_01EB3ED0(void) {
    if (D_001694F8 == 0) {
        D_001694F8 = 1;
        func_01EA9C80(0x35D2325);
    }
}

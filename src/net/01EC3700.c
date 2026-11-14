/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

s32 func_01EC3460(void);
void func_01EC3498(void);
void func_01EC5070(s32, s32);
s32 func_01EC3700(s32 a0, s32 a1) {
    s32 r = func_01EC3460();
    if (r != 0) {
        return r;
    }
    func_01EC5070(a0, a1);
    func_01EC3498();
    return 0;
}

/* cflags:  -Wuninitialized */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;
s32 func_0047C378(s128, s32);                       /* extern */

s32 func_L06_0049C8A0(void *arg0, s128 *arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0xAC);
    if (M2C_FIELD(temp_v1, u8 *, 0x14) == 0) {
        return 0;
    }
    return func_0047C378(*arg1, M2C_FIELD(temp_v1, s32 *, 0)) == 0;
}

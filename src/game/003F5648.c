/* cflags: @ee296 -O2 -G0 -Wa,-G0 */
#include "common.h"
extern u8 D_003CA108[];
s32 func_003F6188(void);
void func_003F5648(u8 *p) {
    s32 i;
    s32 j;
    for (i = 0; i < 16; i++) {
        p[i] = (u32)((f32)func_003F6188() / 2147483520.0f * 256.0f);
    }
    for (j = 0; j < 16; j++) {
        p[j] ^= D_003CA108[j];
    }
}

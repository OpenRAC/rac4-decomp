/* cflags: -O2 -G0 -Wuninitialized */
#include "common.h"
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

#include "pal/l05_0038D700.h"

void func_L05_003E7378(void) {
    s32 var_6;
    void **var_5;
    void *temp_4;

    var_6 = 0x3F;
    var_5 = &D_0038D700[0];
    do {
        temp_4 = *var_5;
        var_6 -= 1;
        var_5 += 1;
        if (temp_4 != NULL) {
            M2C_FIELD(temp_4, s32 *, 0x98) = (s32) M2C_FIELD(M2C_FIELD(temp_4, void **, 0x24), s32 *, 0x10);
        }
    } while (var_6 >= 0);
}

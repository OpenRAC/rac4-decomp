/* cflags: -O2 -G0 -Wuninitialized */
#include "common.h"
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

#include "pal/l05_0038D700.h"

void func_L05_003E7348(void) {
    s32 var_4;
    void **var_2;
    void *temp_3;

    var_4 = 0x3F;
    var_2 = D_0038D700;
    do {
        temp_3 = *var_2;
        var_4 -= 1;
        var_2 += 1;
        if (temp_3 != NULL) {
            M2C_FIELD(temp_3, s32 *, 0x98) = 0;
        }
    } while (var_4 >= 0);
}

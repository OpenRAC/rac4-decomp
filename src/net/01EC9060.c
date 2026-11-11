/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x128];
    s32 f128;
};

s32 func_01EA4570(u32);
void func_01EC8FF0(s32);
extern Type1 *D_00167F38;
extern s32 D_001B6A50[];

void func_01EC9060(void) {
    u32 temp_a0;
    u32 var_s0;

    if (D_001B6A50[0] != 0) {
        var_s0 = 0;
        do {
            temp_a0 = var_s0;
            var_s0 += 1;
            func_01EC8FF0(func_01EA4570(temp_a0));
        } while (var_s0 < 4U);
    }
    if (D_00167F38 != NULL) {
        D_00167F38->f128 = 0;
    }
}

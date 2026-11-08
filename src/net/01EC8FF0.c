/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 {
    u8 pad0[0x128];
    s32 f128;
} Type1;

void func_01EC8FB8(s32, s32);
extern Type1 *D_00167F38;
extern s32 D_001B6A50[];

void func_01EC8FF0(s32 arg0)
{
    s32 i;

    if (arg0 != 0 && D_001B6A50[0] != 0) {
        for (i = 0; i < 0x100; i++) {
            func_01EC8FB8(arg0, i);
        }
    }
    if (D_00167F38 != NULL) {
        D_00167F38->f128 = 0;
    }
}

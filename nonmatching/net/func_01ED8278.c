/* Not matching yet: BYTES 30/184 (tools/try_func.py func_01ED8278 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s16 D_00169CD8;
extern s32 D_1BC948;
extern s32 D_1BCB40;
extern s32 D_1BD290[];
extern s32 func_01ED5DD0(s32, s32, s32, void *);

s32 func_01ED8278(u8 *obj, s32 arg1, s32 arg2)
{
    s32 v28;
    s32 v2C;

    obj[0x14] = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }
    D_1BCB40 = arg1;
    D_00169CD8 = 0;
    v2C = *(s32 *)(obj + 0x2C);
    v28 = *(s32 *)(obj + 0x28);
    D_1BD290[4] = v2C;
    D_1BD290[5] = v28;
    D_1BC948 = arg2;
    D_1BD290[0] = *(s32 *)(obj + 0x18);
    D_1BD290[1] = *(s32 *)(obj + 0x1C);
    D_1BD290[2] = *(s32 *)(obj + 0x20);
    D_1BD290[3] = *(s32 *)(obj + 0x24);
    return func_01ED5DD0(4, 0x12, 0x30, obj) == 0 ? 0 : -5;
}

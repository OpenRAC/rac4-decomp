/* Not matching yet on PAL: 42/52 positional words match (80.77%); 10 differ, size 208/208 bytes (delta 0). */
/* cflags: -O2 -G8 -fno-schedule-insns2 -Wuninitialized */
/* Relocation fields are masked. Reproduce: tools/check_func.py --version pal func_01EE99A0 nonmatching/pal/net/func_01EE99A0.c --diff
 * Scheduling and registers differ; object layouts and callee signatures are inferred. */
#include "common.h"
typedef s32 M2C_UNK;
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

M2C_UNK func_01EE38C4(s32);                         /* extern */
M2C_UNK func_01EE4D48(s32);                         /* extern */

void func_01EE99A0(void *arg0) {
    s32 *temp_3;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 var_17;
    s32 var_18;
    void *temp_2;
    void *temp_4;

    var_18 = 0;
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x635C), s32 *, 8) != 0) {
        var_17 = 0;
loop_2:
        temp_4 = M2C_FIELD((M2C_FIELD(arg0, void **, 0x635C) + var_17), void **, 8);
        var_18 = var_18 + 1;
        M2C_FIELD(M2C_FIELD(temp_4, void **, 0xB0), M2C_UNK (**)(void *, s32), 8)(temp_4, 3);
        temp_2 = (void *)((unsigned char *)(M2C_FIELD(arg0, void **, 0x635C)) + (8));
        temp_3 = temp_2 + var_17;
        var_17 = var_17 + 4;
        *temp_3 = 0;
        if (var_18 < 0x100) {
            if (M2C_FIELD((temp_2 + var_17), s32 *, 0) != 0) {
                goto loop_2;
            }
        }
    }
    temp_4_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x635C), s32 *, 0);
    if (temp_4_2 != 0) {
        func_01EE38C4(temp_4_2);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x635C), s32 *, 0) = 0;
    }
    temp_4_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x635C), s32 *, 4);
    if (temp_4_3 != 0) {
        func_01EE4D48(temp_4_3);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x635C), s32 *, 4) = 0;
    }
}

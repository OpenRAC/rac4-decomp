/* Not matching yet on PAL: 94/100 positional words match (94.00%); 6 differ, size 400/400 bytes (delta 0). */
/* cflags: -O2 -G8 -fno-schedule-insns2 -Wuninitialized */
/* Relocation fields are masked. Reproduce: tools/check_func.py --version pal func_01EF28AC nonmatching/pal/net/func_01EF28AC.c --diff
 * Register allocation differs; callee signatures and object layouts are inferred. */
#include "common.h"
typedef s32 M2C_UNK;
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

M2C_UNK func_01EE68FC(void *, s8 *, s32);           /* extern */
s32 func_01EED8A4(s32, s32, s32);                   /* extern */
s32 func_01EF4188(s32 *, s32, s32, s32, void *);    /* extern */
M2C_UNK func_01F0C090(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_0019C6F0;

s32 func_01EF28AC(s32 *arg0, void *arg1) {
    s32 temp_17;
    s32 temp_18;
    s8 *temp_5;

    temp_17 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x80), s32 *, 4);
    if (M2C_FIELD(arg0, s32 *, 0) == 0) {
        func_01F0C090(&D_0019C6F0, 113);
    }
    if (temp_17 == 0) {
        func_01F0C090(&D_0019C6F0, 114);
    }
    if (arg1 == NULL) {
        func_01F0C090(&D_0019C6F0, 115);
    }
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0xB0), s32 (**)(s32 *), 0x20)(arg0) != 0) {
        if (func_01EED8A4(temp_17, 17, 16) != 0) {
            if (M2C_FIELD(arg1, s32 *, 0x5B10) == 0) {
                temp_5 = M2C_FIELD(arg0, s8 **, 0x144);
                if ((temp_5 != NULL) && (*temp_5 != 0)) {
                    func_01EE68FC(arg1, temp_5, M2C_FIELD(arg0, s32 *, 0x148));
                    return 0;
                }
                goto block_12;
            }
            goto block_13;
        }
block_12:
block_13:
        if ((func_01EED8A4(temp_17, 17, 0) != 0) || (func_01EED8A4(temp_17, 17, 1) != 0) || (func_01EED8A4(temp_17, 17, 2) != 0) || (func_01EED8A4(temp_17, 17, 3) != 0)) {
            temp_18 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x80), s32 *, 0);
            if (temp_18 == 0) {
                func_01F0C090(&D_0019C6F0, 139);
            }
            return func_01EF4188(arg0, temp_17, temp_18, M2C_FIELD(arg0, s32 *, 0), arg1) == 0;
        }
        return 1;
    }
    return 1;
}

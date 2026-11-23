/* Not matching yet: BYTES 9/196 (tools/try_func.py func_L00_007105E0 --diff). Not part of the build. */
/* cflags: -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u8 pad[0x1C];
} Type1;

extern s32 func_0011D9A8(void *p, const char *fmt, ...);
extern void func_L00_007106C0(void);
extern s32 D_00220B60[];
extern Type1 D_003B1738[];
extern s32 D_003F41B8[];

s32 func_L00_007105E0(s32 arg0, u8 *arg1) {
    s32 var_s1;
    s32 var_s4;
    s32 buf;

    var_s1 = 0;
    var_s4 = 1;
    func_L00_007106C0();
    for (; var_s4 != 0 && var_s1 < 5; var_s1++) {
        if (func_0011D9A8((void *)&arg1[0x1B + var_s1 * 9], (const char *)D_00220B60, &buf) == 1) {
            D_003F41B8[var_s1] = buf;
            D_003B1738[var_s1].fC = buf;
        } else {
            var_s4 = 0;
        }
    }
    return 2;
}

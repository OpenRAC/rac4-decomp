/* Not matching yet: SIZE ours 188 / retail 200 (tools/try_func.py func_L00_007105E0 --diff). Not part of the build. */
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

s32 func_L00_007105E0(s32 arg0, s32 arg1) {
    s32 var_s0;
    s32 *var_s2;
    s32 *var_s3;
    s32 var_s1;
    s32 var_s4;
    s32 buf;

    var_s0 = arg1 + 0x1B;
    var_s1 = 0;
    var_s4 = 1;
    func_L00_007106C0();
    var_s3 = D_003F41B8;
    var_s2 = (s32 *)((char *)D_003B1738 + 0xC);
    do {
        if (func_0011D9A8((void *)var_s0, (const char *)D_00220B60, &buf) == 1) {
            var_s0 += 9;
            *var_s3 = buf;
            *var_s2 = buf;
        } else {
            var_s4 = 0;
        }
        var_s3++;
        var_s2 = (s32 *)((char *)var_s2 + 0x2C);
        var_s1++;
    } while (var_s4 != 0 && var_s1 < 5);
    return 2;
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004E3B68 (src/levels/39_multiplayer_menu/L39_004E3B68.c, GPL-3.0), the same code in both games. */

typedef struct N_004E3B68 {
    s32 f[8];
} N_004E3B68;
typedef struct V_004E3B68 {
    s32 _p0[3];
    s32 (*fC)(s32, s32 *, s32, s32, s32, s32);
} V_004E3B68;
typedef struct K_004E3B68 {
    s32 f0;
    s32 f4[21];
    V_004E3B68 *f58;
} K_004E3B68;
typedef struct Type1 {
    s32 _p0[2];
    K_004E3B68 *f8;
} Type1;
extern void func_L00_00538180(N_004E3B68 *);
extern void func_L00_00538038(N_004E3B68 *);
extern s32 func_L00_00537F68(s32 *);
extern void func_L00_00538590(s32, u32, N_004E3B68 *);
extern s32 func_L00_0051F6F0(N_004E3B68 *, N_004E3B68 *, K_004E3B68 *);
extern s32 func_L00_005386D0(N_004E3B68 *, s32);
s32 func_L00_0051F968(Type1 *arg0, s32 arg1, s32 arg2, u32 *arg3, u32 arg4, s32 arg5, u32 arg6, s32 arg7) {
    N_004E3B68 a;
    N_004E3B68 b;
    u32 len;
    K_004E3B68 *key;
    s32 ret;
    s32 r;
    ret = 1;
    if (arg1 != 2) {
        return 2;
    }
    func_L00_00538180(&a);
    func_L00_00538180(&b);
    key = arg0->f8;
    len = (func_L00_00537F68(key->f4) + 7) / 8;
    if (arg4 >= len) {
        if (len < arg6) {
            ret = 3;
        } else {
            func_L00_00538590(arg5, arg6, &a);
            if (func_L00_0051F6F0(&b, &a, key) == 0) {
                r = func_L00_005386D0(&b, arg2);
                if (key->f58->fC(arg2, (s32 *)&len, arg2, r, len, arg7) == 0) {
                    ret = 0;
                    *arg3 = len;
                }
            }
        }
    }
    func_L00_00538038(&b);
    func_L00_00538038(&a);
    return ret;
}

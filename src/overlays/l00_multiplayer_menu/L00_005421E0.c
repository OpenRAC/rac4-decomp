/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 *f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s64 f18;
    u8 *f20;
    u8 *f24;
    u8 **f28;
    s32 f2C;
} Type1;

extern void func_00542440(s32);
extern void func_L00_004F84C8(int, int, int, int, int);
extern s32 func_L00_00535680(void *, u8 **, s64);
extern s32 func_L00_00536038(void *object);
extern s32 func_L00_005360B8(void *arg0, void *arg1);
extern void func_L00_00536348(s32 arg0, s32 arg1);
extern s32 func_L00_005370B0(void *, u8 **, s64);
extern void func_L00_00537430(s32);
extern s32 *func_L00_005423D8(void);
extern s32 func_L00_005463B0(void *, s64);

/* Parses a two-part object from a buffer, allocating it when needed. */
s32 *func_L00_005421E0(s32 **arg0, u8 **arg1, s64 length) {
    Type1 c;
    s32 *ret;

    c.f28 = arg1;
    c.f24 = *arg1;
    c.f8 = 4;
    if (arg0 != 0 && *arg0 != 0) {
        ret = *arg0;
    } else {
        if ((ret = func_L00_005423D8()) == 0) {
            c.f2C = 0x2C;
            goto err;
        }
    }
    c.f0 = *arg1;
    c.f20 = (length == 0) ? 0 : c.f0 + length;
    if (!func_L00_005360B8(&c, &length)) {
        c.f2C = 0x2F;
        goto err;
    }
    c.f24 = c.f0;
    if (!func_L00_00535680(ret, &c.f0, c.f18)) {
        c.f2C = 0x30;
        goto err;
    }
    c.f18 -= c.f0 - c.f24;
    if (!((c.fC & 1) == 0 ? (c.f18 <= 0) : (c.f4 = func_L00_005463B0(&c, c.f18)))) {
        c.f24 = c.f0;
        if (!func_L00_005370B0(ret + 1, &c.f0, c.f18)) {
            c.f2C = 0x32;
            goto err;
        }
        c.f18 -= c.f0 - c.f24;
    } else {
        func_L00_00537430(ret[1]);
        ret[1] = 0;
    }
    if (!func_L00_00536038(&c)) {
        c.f2C = 0x38;
        goto err;
    }
    *arg1 = c.f0;
    if (arg0 != 0) *arg0 = ret;
    return ret;
err:
    func_L00_004F84C8(0xD, 0xA0, c.f8, 0, 0);
    func_L00_00536348((s32)*arg1, c.f24 - *arg1);
    if (ret != 0 && (arg0 == 0 || *arg0 != ret)) func_00542440((s32)ret);
    return 0;
}

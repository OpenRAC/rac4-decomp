#include "common.h"

extern s32 func_004E7EC8(s32 *);
extern void func_004985F0(s32);
extern void func_004D6590(s32);
extern const char *func_0045E850(s32);
extern void func_0049F4C8(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);
extern s32 D_0031CCC4[];

void func_004D66D0(void)
{
    s32 index;
    s32 *p;
    s32 *obj;
    const char *result;

    if (D_0031CCC4[20] == 0) {
        return;
    }
    index = D_0031CCC4[21];
    if (index < 0) {
        p = 0;
    } else {
        p = (s32 *)(D_0031CCC4[13] + index * 24);
    }
    obj = (s32 *)p[2];
    if (func_004E7EC8(obj) == 0) {
        goto fallback;
    }
    if (obj[2] <= 0) {
        func_004D6590(1);
        return;
    }
    result = func_0045E850(0x8D0);
    func_0049F4C8(4, result, func_004D6590, 3, 0, 0, 0, -1.0f);
    return;

fallback:
    func_004985F0(4);
}

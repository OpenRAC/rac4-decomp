/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011A2DC();
extern s32 func_L00_0051CF38(s32 *arg0);
extern s32 func_L00_005262E0(void *arg0, s32 arg1, s32 *arg2, s32 *arg3);
extern s32 func_L00_0052D6C0();
extern s32 func_L00_005387E0(void *, s32);

// Compares two objects of the same type: kinds 6 and 0x74 are tested field by field, kind 0x1C never matches.
s32 func_L00_0052DD50(s32 *arg0, s32 *arg1) {
    s32 ret = 0;
    s32 r;
    s32 a;
    s32 b;
    s32 v[4];
    s32 *s1 = (s32 *)func_L00_0052D6C0(arg0);
    s32 kind = func_L00_0051CF38(s1);

    if (kind == func_L00_0051CF38(arg1)) {
        switch (kind) {
        case 0x1C:
            goto end;
        case 6:
            if (func_L00_005262E0((void *)s1[3], 0x10, &v[0], &v[1])) goto end;
            if (func_L00_005262E0((void *)arg1[3], 0x10, &v[2], &v[3])) goto end;
            if (v[1] != v[3]) goto end;
            b = v[2];
            a = v[0];
            if (func_0011A2DC(a, b, v[1])) goto end;
            if (func_L00_005262E0((void *)s1[3], 0x11, &v[0], &v[1])) goto end;
            if (func_L00_005262E0((void *)arg1[3], 0x11, &v[2], &v[3])) goto end;
            if (v[1] != v[3]) goto end;
            b = v[2];
            a = v[0];
            r = func_0011A2DC(a, b, v[1]);
            break;
        case 0x74:
            r = func_L00_005387E0((void *)*(s32 *)((u8 *)s1[3] + 0x18), *(s32 *)((u8 *)arg1[3] + 0x18));
            break;
        default:
            goto end;
        }
        if (r == 0) {
            ret = 1;
            r = 1;
        }
    }
end:
    return ret;
}

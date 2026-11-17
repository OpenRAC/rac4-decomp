#include "common.h"

extern void func_005015B8(s32 *arg0);
extern s32 func_005015C8(s32 *arg0);

/* Removes the entry arg1 from the table at arg0, shifts the later entries down and frees the displaced ones. */
s32 func_0050C9A8(s32 *arg0, s32 arg1) {
    s32 result;
    s32 i;
    s32 next;
    s32 *p;
    s32 *q;

    result = 0;
    if (arg1 >= 0 && arg1 < arg0[0x7A]) {
        p = (s32 *)(arg1 * 4 + (s32)arg0);
        p += 0x10;
        if (*p != 0) {
            func_005015C8((s32 *)*p);
        }
        *p = 0;
        if (arg1 < 0x67) {
            i = arg1;
            if (i < arg0[0x7A] - 1) {
                do {
                    q = &arg0[i + 0x11];
                    next = *q;
                    if (q[-1] != 0) {
                        func_005015C8((s32 *)q[-1]);
                    }
                    q[-1] = next;
                    if (next != 0) {
                        func_005015B8((s32 *)next);
                    }
                    i++;
                } while (i < arg0[0x7A] - 1);
            }
            p = (s32 *)(arg0[0x7A] * 4 + (s32)arg0);
            p += 0xF;
            if (*p != 0) {
                func_005015C8((s32 *)*p);
            }
            *p = 0;
        }
        result = 1;
        arg0[0x7A]--;
    }
    return result;
}

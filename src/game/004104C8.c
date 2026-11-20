/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 cap; s32 n; void *d; } S;
extern void *func_004033B0(s32);
extern void func_00403308(void *, s32, s32);
extern void func_00403330(void *, void *, s32);
extern void func_00403440(void *);
s32 func_004104C8(s32 n, S *s) {
    s32 r = 0;
    void *p;
    void *q;
    s32 bytes = n * 8;
    if (s->cap < n) {
        if (s->d == 0) {
            s->cap = n;
            p = func_004033B0(bytes);
            s->d = p;
            if (p == 0) {
                s->cap = 0;
                return 0x100;
            }
            return 0;
        }
        q = func_004033B0(bytes);
        if (q != 0) {
            func_00403330(q, s->d, s->n * 8);
            func_00403308(s->d, 0, s->cap * 8);
            func_00403440(s->d);
            s->cap = n;
            s->d = q;
            return 0;
        }
        func_00403308(s->d, 0, s->cap * 8);
        func_00403440(s->d);
        s->cap = 0;
        s->n = 0;
        s->d = 0;
        return 0x100;
    }
    return r;
}

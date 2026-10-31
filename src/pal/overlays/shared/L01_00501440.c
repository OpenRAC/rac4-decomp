/* cflags: -O2 -G8 */
#include "common.h"
typedef int s128 __attribute__((mode(TI)));
extern void func_0046C6B0(void *);
extern void func_00449A28(void *, void (*)(), void *);
extern void func_L01_00501590();
extern int D_00222B9C;
void func_L01_00501440(void *arg0) {
    void *p = *(void **)((char *)arg0 + 0xAC);
    void *q = *(void **)((char *)p + 4);
    int n;
    if (q) {
        if (*(float *)((char *)q + 0x2E20) <= 0.0f)
            *(void **)((char *)p + 4) = 0;
        else
            *(s128 *)((char *)arg0 + 0x10) = *(s128 *)((char *)q + 0xF0);
    }
    n = *(int *)p + 1;
    *(int *)p = n;
    if (*(void **)((char *)p + 4)) {
        if (n >= 43) goto destroy;
        goto call;
    }
    if (n >= 18) {
    destroy:
        func_0046C6B0(arg0);
        return;
    }
call:
    func_00449A28(&D_00222B9C, func_L01_00501590, arg0);
}

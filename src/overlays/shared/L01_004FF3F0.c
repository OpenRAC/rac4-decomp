/* cflags: -O2 -G8 */
#include "common.h"
typedef int s128 __attribute__((mode(TI)));
extern void func_00586E80(void *);
extern void func_0054A4E8(void *, void (*)(), void *);
extern void D_004FF540();
extern int D_00222A9C;
void func_L01_004FF3F0(void *arg0) {
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
        if (n >= 51) goto destroy;
        goto call;
    }
    if (n >= 21) {
    destroy:
        func_00586E80(arg0);
        return;
    }
call:
    func_0054A4E8(&D_00222A9C, D_004FF540, arg0);
}

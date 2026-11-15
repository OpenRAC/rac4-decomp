/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_00517808(void);

/* calls a virtual method with an optional out-parameter and returns the result it stores */
s32 func_L00_00538AD8(void *arg0, s32 *arg1) {
    s32 tmp;
    void **self = arg0;
    s32 *out = arg1;
    void *(*fn)(void) = *(void *(**)(void))((u8 *)func_00517808() + 0xC);

    if (out == 0) {
        out = &tmp;
    }
    if (self == 0) {
        self = (void **)fn();
    }
    if ((*(s32 (**)(void *, s32 *))((u8 *)self + 0x10))(self, out) == 0) {
        return *out;
    }
    return 0;
}

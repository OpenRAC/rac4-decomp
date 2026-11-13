/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_01EEE13C(void);
extern void *func_01EF04A4(s32, s32, s32, s32, void *);
extern void func_01F0C090(void *, s32);
extern char D_0019E5D8[];
void *func_01F0A63C(s32 arg0) {
    void *p = func_01EF04A4(func_01EEE13C(), arg0, 0, 0xB6, D_0019E5D8);
    if (p == NULL) {
        func_01F0C090(D_0019E5D8, 0xB9);
    }
    return p;
}

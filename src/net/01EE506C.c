/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_01EEE13C(void);
extern void *func_01EF04A4(s32, s32, s32, s32, void *);
extern void func_01F0C090(void *, s32);
extern char D_0019B160[];
void *func_01EE506C(s32 arg0) {
    void *p = func_01EF04A4(func_01EEE13C(), arg0, 0, 0x69, D_0019B160);
    if (p == NULL) {
        func_01F0C090(D_0019B160, 0x6C);
    }
    return p;
}

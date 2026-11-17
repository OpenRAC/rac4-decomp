/* cflags: @ee296 -O2 -G0 -fno-schedule-insns -mno-split-addresses */
#include "common.h"

typedef struct { s32 x[6]; } Type1;
extern s32 func_01EEE13C(void);
extern Type1 *func_01EF04A4(s32, s32, s32, s32, void *);
extern char D_0019C7B8[];
void func_01EF3C70(u8 *arg0, Type1 *arg1) {
    Type1 *p = func_01EF04A4(func_01EEE13C(), 0x18, 0, 0xE0, D_0019C7B8);
    *(Type1 **)(arg0 + 0x80) = p;
    *p = *arg1;
}

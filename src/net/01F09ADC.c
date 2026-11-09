/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x8B88];
    s32 f8B88;
    s32 f8B8C;
};

void func_01EED528(s32);
void func_01EF0C1C(void *);
void func_01F088BC(void *, s32);
void func_01F094CC(void *);

void func_01F09ADC(Type1 *arg0, s32 arg1, s32 arg2) {
    if ((arg2 == 0) || (arg0->f8B8C != arg0->f8B88)) {
        func_01EED528(0x1D);
        func_01F094CC(arg0);
    }
    func_01EF0C1C((u8 *)arg0 + 0x8BC4);
    func_01F088BC(arg0, 3);
}

/* cflags: @ee296 -Os -G0 -fno-optimize-sibling-calls -mno-split-addresses */
#include "common.h"

typedef struct {
    s32 f0;
    char _p4[0x7C];
    void **f80;
} Type1;
extern void func_01F0C090(void *, s32);
extern char D_0019D9E8[];
void func_01EFEACC(Type1 *arg0) {
    if (*arg0->f80 == NULL) {
        func_01F0C090(D_0019D9E8, 0xB0);
    }
    if (arg0->f0 == 0) {
        func_01F0C090(D_0019D9E8, 0xB1);
    }
}

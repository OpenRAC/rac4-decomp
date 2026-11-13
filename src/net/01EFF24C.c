/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct {
    char _p0[0x63E4];
    void *f63E4[64];
} Type1;
extern void func_01F0C090(void *, s32);
extern void func_01EFE528(void *);
extern char D_0019D9E8[];
void func_01EFF24C(Type1 *arg0, void *arg1) {
    s32 i;
    for (i = 0; i < 64; i++) {
        void *p = arg0->f63E4[i];
        if (p == NULL) {
            func_01F0C090(D_0019D9E8, 0x1A4);
        }
        if (p == arg1) {
            func_01EFE528(p);
            return;
        }
    }
}

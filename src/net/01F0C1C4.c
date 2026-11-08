/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xB0];
    void *fB0;
};

void func_01EF3748(void *);
extern s32 D_0016FF60[];

void func_01F0C1C4(Type1 *arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = arg1 & 1;
    arg0->fB0 = D_0016FF60;
    if (temp_a1 != 0) {
        func_01EF3748(arg0);
    }
}

/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x264];
    void *f264;
};

void func_01F07720(void *);
extern s32 D_00170E68[];

void func_01F0760C(Type1 *arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = arg1 & 1;
    arg0->f264 = D_00170E68;
    if (temp_a1 != 0) {
        func_01F07720(arg0);
    }
}

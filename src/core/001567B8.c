/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x8];
    void *f8;
};

void func_01EF58F4(void *);
extern s32 D_00170020[];

void func_001567B8(Type1 *arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = arg1 & 1;
    arg0->f8 = D_00170020;
    if (temp_a1 != 0) {
        func_01EF58F4(arg0);
    }
}

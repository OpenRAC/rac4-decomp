/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xB8];
    s32 fB8;
};

void func_01EEDCD0(s32, void *, s32);
extern s32 D_0019E078[];

void func_01F045E8(Type1 *arg0) {
    func_01EEDCD0((void *)((u8 *)arg0 + 0x38), D_0019E078, 0x40);
    arg0->fB8 = 1;
}

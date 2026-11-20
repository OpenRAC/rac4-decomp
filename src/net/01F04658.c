/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xB0];
    void *fB0;
    s32 fB4;
};

void func_01EF382C(void *);
void func_01F045E8(Type1 *);
s32 func_01F0471C(Type1 *, s32);
s32 func_01F047A0(Type1 *, s32);
s32 func_01F048C4(Type1 *, s32, void *, s32 *);
void func_01F0C090(char *, s32);
extern void *D_00170C48[];
extern s32 D_0019E080[];
extern s32 D_0019E090[];

void func_01F04658(Type1 *arg0, s32 arg1) {
    func_01EF382C(arg0);
    arg0->fB0 = D_00170C48;
    func_01F045E8(arg0);
    func_01F048C4(arg0, arg1, D_0019E080, &arg0->fB4);
    switch (arg0->fB4) {
    case 0:
    case 1:
        func_01F0471C(arg0, arg1);
        break;
    case 2:
        func_01F047A0(arg0, arg1);
        break;
    default:
        func_01F0C090((char *)D_0019E090, 0x32);
        break;
    }
}

/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    char _p4[0xAC];
    void *fB0;
    char _pB4[0x104];
    s32 f1B8;
};

s32 func_01EE394C(s32);
s32 func_01EE3A18(s32, void *);
s32 func_01EF30EC(s32, void *, void *);
void func_01EF382C(void *, s32, s32);
void func_01F0381C(void *);
void func_01F03950(void *, s32);
void func_01F03B10(void *, s32, s32);
void func_01F0C090(void *, s32);
extern s32 D_00170B28[];
extern s32 D_0019DF70[];
extern s32 D_0019DF78[];
extern s32 D_0019DF90[];

void func_01F03864(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    func_01EF382C(arg0, arg1, arg3);
    arg0->fB0 = D_00170B28;
    func_01F0381C(arg0);
    temp_v0 = func_01EE3A18(arg0->f0, D_0019DF70);
    if (temp_v0 != 0) {
        func_01F03950(arg0, temp_v0);
    } else {
        func_01F0C090(D_0019DF78, 0x2F);
    }
    if (func_01EF30EC(arg0->f0, D_0019DF90, (void *)((u8 *)arg0 + 0x1B8)) == 0) {
        arg0->f1B8 = 0;
    }
    func_01F03B10(arg0, func_01EE394C(arg0->f0), arg2);
}

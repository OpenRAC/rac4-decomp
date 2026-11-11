/* cflags: @ee296 -Os -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    char _p4[0xAC];
    void *fB0;
    s32 fB4;
    s32 fB8;
};

s32 func_01EEE12C(void);
void func_01EEED4C(s32, s32);
s32 func_01EF308C(s32, s32, s32 *);
s32 func_01EF339C(s32, void *, void *);
void func_01EF382C(void *, s32, s32);
void func_01EF64F0(void *);
void func_01EF6720(void *);
void func_01EF681C(void *);
void func_01EF68E8(void *);
void func_01EF697C(void *);
extern s32 D_001701A8[];
extern s32 D_0019CB18[];
extern s32 D_0019CB28[];

void func_01EF6594(Type1 *arg0, s32 arg1, s32 arg2) {
    func_01EF382C(arg0, arg1, arg2);
    arg0->fB0 = D_001701A8;
    func_01EF64F0(arg0);
    func_01EF308C(arg0->f0, (s32)D_0019CB18, &arg0->fB4);
    func_01EF339C(arg0->f0, D_0019CB28, &arg0->fB8);
    if (arg0->fB8 != 0) {
        func_01EEED4C(func_01EEE12C(), arg0->fB8);
    }
    func_01EF697C(arg0);
    func_01EF68E8(arg0);
    func_01EF6720(arg0);
    func_01EF681C(arg0);
}

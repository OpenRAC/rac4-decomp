/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    char _p4[0xAC];
    void *fB0;
    char _pB4[0x4];
    s32 fB8;
    s32 fBC;
};

s32 func_01EE3A18(s32, void *);
void func_01EF3318(s32, void *, void *);
void func_01EF382C();
void func_01EF6E1C(void *);
void func_01EF7140(void *, s32, void *, void *);
void func_01F06988(s32);
extern s32 D_001702C8[];
extern s32 D_0019CCB8[];
extern s32 D_0019CCC0[];
extern s32 D_0019CCD0[];

void func_01EF6E5C(Type1 *arg0) {
    s32 temp_v0;

    func_01EF382C();
    arg0->fB0 = D_001702C8;
    func_01EF6E1C(arg0);
    func_01EF7140(arg0, arg0->f0, D_0019CCB8, (void *)((u8 *)arg0 + 0xB4));
    arg0->fBC = 0;
    func_01EF3318(arg0->f0, D_0019CCC0, (void *)((u8 *)arg0 + 0xBC));
    temp_v0 = func_01EE3A18(arg0->f0, D_0019CCD0);
    arg0->fB8 = temp_v0;
    if (temp_v0 != 0) {
        func_01F06988(temp_v0);
    }
}

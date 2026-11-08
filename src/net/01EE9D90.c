/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    void *f0;
    s32 f4;
    char _p8[0x10];
    s32 f18;
    s32 f1C;
    s32 f20;
    char _p24[0x114];
    s32 f138;
    char _p13C[0x8974];
    s32 f8AB0;
    s32 f8AB4;
    char _p8AB8[0x4];
    s32 f8ABC;
    s32 f8AC0;
};

void func_01EE9F5C(void *, s32);
void func_01EEC484(void *, s32);
void func_01EF0ADC(void *, s32);
void func_01EF21FC(void *);
void func_01F07050();
extern s32 D_0016FCC0[];

void func_01EE9D90(Type1 *arg0, s32 arg1, s32 arg2) {
    func_01F07050();
    arg0->f0 = D_0016FCC0;
    func_01EF21FC((void *)((u8 *)arg0 + 0x13C));
    func_01EF0ADC((void *)((u8 *)arg0 + 0x540), 0);
    func_01EF21FC((void *)((u8 *)arg0 + 0x86AC));
    arg0->f4 = 0;
    func_01EEC484(arg0, 0);
    arg0->f8AB0 = 0;
    arg0->f138 = arg1;
    arg0->f8AB4 = 0;
    arg0->f8ABC = 0;
    arg0->f8AC0 = 0;
    arg0->f18 = 0;
    arg0->f1C = 0;
    arg0->f20 = 0;
    func_01EE9F5C(arg0, arg2);
}

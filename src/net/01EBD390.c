/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type1 {
    char _p0[0x19C];
    u16 f19C;
};
struct Type2 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s16 f24;
    char _p26[0x2];
    char f28[0x8];
    s32 f30;
    s16 f34;
    char f36[0x8];
    char f3E[0x8];
    char _p46[0x2];
    s32 f48;
    void *f4C;
};

void func_0011A518(void *, s32, s32);
void func_01EA8B78(void *);

void func_01EBD390(Type1 *arg0, Type2 *arg1) {
    if (arg1 != NULL) {
        arg1->f0 = 0;
        arg1->f4 = 0;
        arg1->f8 = 0;
        arg1->fC = 0;
        arg1->f10 = 0;
        arg1->f14 = 0;
        arg1->f18 = 0;
        arg1->f1C = 0;
        arg1->f20 = 0;
        arg1->f24 = 0;
        func_01EA8B78(arg1->f28);
        arg1->f30 = 0;
        arg1->f34 = 0;
        func_0011A518(arg1->f36, 0, 8);
        func_0011A518(arg1->f3E, 0, 8);
        arg1->f48 = 0;
        func_0011A518(arg1->f4C, 0, ((u32)(arg0->f19C + 0x1F) >> 5) * 4 + 4);
    }
}

#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x8];
    s32 f8;
    char _pC[0x5C];
    s32 f68;
    s32 f6C;
    s32 f70;
};

extern s32 func_0045DE00(void);
extern void func_00499CE0(s32 arg0);
extern void func_0049B0D8(s32 arg0);
extern void func_0049C4B0(s32, s32, s32, s32);
extern void func_004C5570(void);
extern s32 func_00505B20(void);
extern s32 D_00221880;
extern s32 D_00221888;
extern Type1 D_0030B7F8[];

void func_004C1E98(void) {
    s32 index;
    Type1 *p;

    func_0045DE00();
    index = func_00505B20();
    p = &D_0030B7F8[index];
    p->f8 = 0;
    func_0049C4B0(index, 0, D_00221880, 0);
    func_0049C4B0(index, 1, D_00221880, 0);
    func_0049C4B0(index, 2, D_00221888, 0);
    func_0049C4B0(index, 3, D_00221888, 0);
    func_004C5570();
    if (p->f70 != 0) {
        func_00499CE0(p->f70);
        p->f70 = 0;
    }
    if (p->f68 != 0) {
        func_00499CE0(p->f68);
        p->f68 = 0;
    }
    if (p->f6C != 0) {
        func_00499CE0(p->f6C);
        p->f6C = 0;
    }
    func_0049B0D8(index);
}

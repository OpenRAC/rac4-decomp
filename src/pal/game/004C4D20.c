#include "common.h"
typedef struct {
    s32 mode, a, flags, b, selection;
    char rest[0x60];
} State;
extern State D_0030B7F8[];
extern s32 D_00221988;
extern s32 func_00506BB8(void), func_004A2798(s32 *, s32), func_005062D0(s32, const char *);
extern const char *func_0045E850(s32);
extern void func_0049D060(s32, s32, s32), func_0049CF80(s32, s32), func_004C47B0(void), func_004C41F8(void), func_004985F0(s32);
void func_004C4D20(void)
{
    s32 index = func_00506BB8();
    State *p = D_0030B7F8 + index;
    func_0049D060(index, 0, 1);
    func_0049D060(index, 1, 1);
    func_0049CF80(index, 2);
    func_0049CF80(index, 3);
    switch (p->selection) {
    case 1: {
        s32 handle;
        func_004C47B0();
        handle = func_004A2798(&D_00221988, 0x51);
        func_005062D0(handle, func_0045E850(0x304F));
    } break;
    case 2: {
        s32 handle;
        func_004C41F8();
        handle = func_004A2798(&D_00221988, 0x50);
        func_005062D0(handle, func_0045E850(0x304E));
    } break;
    }
    func_004985F0(8);
    p->mode = 1;
    p->flags |= 0x80;
}

#include "common.h"
typedef struct {
    s32 a, b, flags, selection;
    char pad[0x60];
    s32 handle;
} State;
typedef struct {
    char pad[0x29];
    u8 label;
} Info;
extern State D_0030B7F8[];
extern char D_001CDA00[];
extern s32 D_00221980;
extern s32 func_00506BB8(void), func_00498518(s32), func_0049A9D8(void *, s32), func_004A2798(s32 *, s32), func_005071B8(s32, s32);
extern void *func_00511CC0(s32);
extern Info *func_0054A290(s32, s32);
extern void func_0049AA18(s32);
void func_004C32B8(void)
{
    s32 index = func_00506BB8();
    State *p;
    char *text;
    func_00511CC0(index);
    p = D_0030B7F8 + index;
    text = D_001CDA00 + func_0054A290(func_00498518(p->selection), 0)->label * 8;
    if (p->handle) {
        func_0049AA18(p->handle);
        p->handle = 0;
    }
    p->handle = func_0049A9D8(text, -1);
    func_005071B8(func_004A2798(&D_00221980, 0x1D), p->handle);
    p->flags &= ~4;
}

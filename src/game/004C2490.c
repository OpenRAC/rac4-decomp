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
extern char D_001CD980[];
extern s32 D_00221880;
extern s32 func_00505B20(void), func_004978C0(s32), func_00499CA0(void *, s32), func_004A1A60(s32 *, s32), func_00506120(s32, s32);
extern void *func_00510BE8(s32);
extern Info *func_00548D28(s32, s32);
extern void func_00499CE0(s32);
void func_004C2490(void)
{
    s32 index = func_00505B20();
    State *p;
    char *text;
    func_00510BE8(index);
    p = D_0030B7F8 + index;
    text = D_001CD980 + func_00548D28(func_004978C0(p->selection), 0)->label * 8;
    if (p->handle) {
        func_00499CE0(p->handle);
        p->handle = 0;
    }
    p->handle = func_00499CA0(text, -1);
    func_00506120(func_004A1A60(&D_00221880, 0x1D), p->handle);
    p->flags &= ~4;
}

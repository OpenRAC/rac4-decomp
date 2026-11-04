#include "common.h"

extern s32 D_003099F0[];
extern s32 D_00171250[];
extern char D_0021F8C0[];
extern s32 func_00511CC0(s32);
extern s32 func_0045E850(s32);
extern void func_0011D920(void *, char *, ...);

s32 D_0021F8B0 = 0x2F1B;
s32 D_0021F8B4 = 0x2F19;
s32 D_0021F8B8 = 0x2F1A;

/* Resolve indexed values and invoke the four-argument handler. */
void func_004B68A8(s32 arg0)
{
    s32 item = arg0 * 0x1F8 + (s32)D_003099F0;
    s32 state = func_00511CC0(arg0);
    char *base = D_0021F8C0;
    s32 index;
    s32 value;
    s32 first;
    s32 second;
    item += 0x14;
    index = *(s32 *)(state + 0x2F10);
    value = D_00171250[index];
    first = func_0045E850(0x315F);
    second = func_0045E850(*(s32 *)((s32)&D_0021F8B0 + value * 4));
    func_0011D920((void *)item, base, first, second);
}

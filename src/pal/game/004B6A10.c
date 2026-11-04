#include "common.h"

extern s32 D_003099F0[];
extern s32 D_00171250[];
extern s32 D_00171E80[];
extern char D_0021F8C0[];
extern s32 func_00511CC0(s32);
extern s32 func_0045E850(s32);
extern void func_0011D920(void *, char *, ...);

s32 D_0021F8D0 = 0x192;
s32 D_0021F8D4 = 0x193;

/* Resolve grouped values and invoke the format handler. */
void func_004B6A10(s32 arg0)
{
    s32 item = arg0 * 0x1F8 + (s32)D_003099F0;
    s32 state = func_00511CC0(arg0);
    char *format = D_0021F8C0;
    s32 index;
    s32 value;
    s32 first;
    s32 second;
    s32 entry;
    item += 0x94;
    index = *(s32 *)(state + 0x2F10) * 4;
    value = D_00171250[index / 4];
    first = func_0045E850(0x3161);
    entry = *(s32 *)((s32)D_00171E80 + value * 0x28 + index);
    second = func_0045E850(*(s32 *)((s32)&D_0021F8D0 + entry * 4));
    func_0011D920((void *)item, format, first, second);
}

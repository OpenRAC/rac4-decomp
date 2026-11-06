#include "common.h"

extern s32 D_003098F0[];
extern s32 D_001711D0[];
extern s32 D_00171E78[];
extern char D_0021F820[];
extern void *func_00510BE8(s32);
extern const char *func_0045E038(s32);
extern s32 func_0011D920(char *, const char *, ...);

s32 D_0021F828 = 0x192;
s32 D_0021F82C = 0x193;

/* Resolve grouped values and invoke the format handler. */
void func_004B5A60(s32 arg0)
{
    s32 item = arg0 * 0x1F8 + (s32)D_003098F0;
    s32 state = (s32)func_00510BE8(arg0);
    char *format = D_0021F820;
    s32 index;
    s32 value;
    const char *first;
    const char *second;
    s32 entry;
    item += 0x54;
    index = *(s32 *)(state + 0x2F10) * 4;
    value = D_001711D0[index / 4];
    first = func_0045E038(0x3160);
    entry = *(s32 *)((s32)D_00171E78 + value * 0x28 + index);
    second = func_0045E038(*(s32 *)((s32)&D_0021F828 + entry * 4));
    func_0011D920((char *)item, format, first, second);
}

#include "common.h"

extern s32 D_003098F0[];
extern s32 D_001711D0[];
extern char D_0021F820[];
extern void *func_00510BE8(s32);
extern const char *func_0045E038(s32);
extern s32 func_0011D920(char *, const char *, ...);

s32 D_0021F810 = 0x2F1B;
s32 D_0021F814 = 0x2F19;
s32 D_0021F818 = 0x2F1A;

/* Resolve indexed values and invoke the four-argument handler. */
void func_004B59B8(s32 arg0)
{
    s32 item = arg0 * 0x1F8 + (s32)D_003098F0;
    s32 state = (s32)func_00510BE8(arg0);
    char *base = D_0021F820;
    s32 index;
    s32 value;
    const char *first;
    const char *second;
    item += 0x14;
    index = *(s32 *)(state + 0x2F10);
    value = D_001711D0[index];
    first = func_0045E038(0x315F);
    second = func_0045E038(*(s32 *)((s32)&D_0021F810 + value * 4));
    func_0011D920((char *)item, base, first, second);
}

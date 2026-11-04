#include "common.h"
typedef struct {
    u8 prefix[8];
    s16 text;
} Descriptor;
extern Descriptor *func_0054A290(s32, s32);
extern char *func_0045E850(s32);
extern s32 func_0011D920(char *, const char *, ...);
extern void func_00549050(const char *, s32, s32);
extern const char D_00220F58[];

void func_0054A5A0(s32 item, s32 slot, s32 duration, s32 level)
{
    char text[128];
    s32 suffix;
    const char *name, *label, *format;
    if (duration > 0 && item > 0 && slot >= 0 && level >= 0) {
        suffix = item == 2 ? 0x25A5 : 0x2557;
        format = D_00220F58;
        name = func_0045E850(func_0054A290(item, 0)->text);
        label = func_0045E850(suffix);
        func_0011D920(text, format, name, label, level + 1);
        func_00549050(text, slot, duration);
    }
}

#include "common.h"

extern const char *func_0045E850(s32);
extern s32 func_0011D920(char *, const char *, ...);
extern void func_00549050(const char *, s32, s32), func_004978E8(s32, const char *);
extern char D_00220F68[], D_00355220[];
extern s32 D_0022216C;
void func_0054AFA0(s16 id, s32 slot, s32 duration)
{
    char buffer[128];
    const char *format;
    if (duration > 0 && id > 0 && slot >= 0) {
        const char *label;
        format = D_00220F68;
        label = func_0045E850(0x2558);
        func_0011D920(buffer, format, label, func_0045E850(id));
        func_00549050(buffer, slot, duration);
    }
    func_004978E8(D_0022216C, D_00355220);
}

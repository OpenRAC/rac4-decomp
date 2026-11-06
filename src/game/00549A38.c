#include "common.h"

extern const char *func_0045E038(s32);
extern s32 func_0011D920(char *, const char *, ...);
extern void func_00547B08(const char *, s32, s32), func_00496C90(s32, const char *);
extern char D_00220EC8[], D_00355220[];
extern s32 D_0022206C;
void func_00549A38(s16 id, s32 slot, s32 duration)
{
    char buffer[128];
    const char *format;
    if (duration > 0 && id > 0 && slot >= 0) {
        const char *label;
        format = D_00220EC8;
        label = func_0045E038(0x2558);
        func_0011D920(buffer, format, label, func_0045E038(id));
        func_00547B08(buffer, slot, duration);
    }
    func_00496C90(D_0022206C, D_00355220);
}

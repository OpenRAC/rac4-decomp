#include "common.h"

typedef struct {
    s32 unused;
    s32 id;
} EffectName;

extern const char *func_0045E850(s32 id);
extern s32 func_0011D920(char *dst, const char *format, ...);
extern const EffectName D_0021F5B0[];
extern const char D_0021F5C0[];

char *func_00496F68(char *dst, s32 selector)
{
    s32 skip;
    s32 id;
    const char *format;
    const char *name;

    switch (selector) {
    case 2:
    case 5:
    case 10:
    case 23:
    case 24:
    case 25:
    case 26:
        skip = 0;
        break;
    default:
        skip = 1;
        break;
    }

    if (!skip) {
        format = D_0021F5C0;
        if (selector >= 0)
            id = D_0021F5B0[selector % 80].id;
        else
            id = 0;
        name = func_0045E850(id);
        func_0011D920(dst, format, name);
    }
    return dst;
}

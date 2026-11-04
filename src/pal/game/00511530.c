#include "common.h"

typedef struct Type2 {
    char pad[0x34];
    f32 f34, f38;
    char pad3C[4];
    u16 f40;
    char pad42[14];
    u8 f50;
} Type2;
typedef struct Type1 {
    char pad[0x1C];
    f32 f1C, f20;
    char pad24[0x1C];
    Type2 *f40;
    char pad44[4];
    f32 f48, f4C;
} Type1;
extern void func_00454B68(s32), func_00510158(Type1 *), func_00510510(Type1 *, f32 *, f32, f32);
s32 func_00511530(Type1 *p)
{
    s32 mode = p->f40->f50;
    switch (mode) {
    case 1:
        func_00454B68(1);
        break;
    case 2:
        func_00454B68(0);
        break;
    case 0:
    default:
        func_00454B68(0);
        break;
    }
    if (p->f40->f40 & 4) {
        Type2 *state;
        func_00510158(p);
        state = p->f40;
        if (state->f40 & 0x80)
            func_00510510(p, &state->f34, p->f1C, p->f48);
        else
            func_00510510(p, &state->f38, p->f20, p->f4C);
    }
    return 0;
}

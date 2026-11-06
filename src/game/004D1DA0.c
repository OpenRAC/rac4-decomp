#include "common.h"
typedef struct {
    s32 state, pad, flags;
    char rest[0x150];
} State;
extern State D_0031B050[];
extern s32 func_00505B20(void);
extern void func_004A1358(void *), func_004A1310(void *);
extern s32 func_004E21D8(s32, s32, void *);
extern s32 func_004E0858(void);
void func_004D1DA0(s32 forward)
{
    State *p = D_0031B050 + func_00505B20();
    char *context = (char *)p + 0xF0;
    if (*(s32 *)(context + 0x50) >= 2) {
        if (forward)
            func_004A1358(context);
        else
            func_004A1310(context);
        func_004E21D8(0, 0, 0);
        func_004E0858();
        p->flags |= 6;
    }
}

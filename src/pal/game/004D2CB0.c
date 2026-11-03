#include "common.h"
typedef struct {
    s32 state, pad, flags;
    char rest[0x150];
} State;
extern State D_0031B050[];
extern s32 func_00506BB8(void);
extern void func_004A2090(void *), func_004A2048(void *);
extern s32 func_004E3138(s32, s32, void *);
extern s32 func_004E17B8(void);
void func_004D2CB0(s32 forward)
{
    State *p = D_0031B050 + func_00506BB8();
    char *context = (char *)p + 0xF0;
    if (*(s32 *)(context + 0x50) >= 2) {
        if (forward)
            func_004A2090(context);
        else
            func_004A2048(context);
        func_004E3138(0, 0, 0);
        func_004E17B8();
        p->flags |= 6;
    }
}

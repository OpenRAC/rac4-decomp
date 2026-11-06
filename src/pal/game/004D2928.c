#include "common.h"
typedef struct {
    s32 mode, a, flags;
    char gap[0xE4];
    char list[0x6C];
} State;
extern State D_0031B050[];
extern s32 func_00506BB8(void), func_004A2468(void *);
extern void func_004D2D48(void), func_004D2AD0(void), func_004D2B10(void), func_004D2C08(void), func_00502520(void *);
void func_004D2928(void *descriptor)
{
    State *p = D_0031B050 + func_00506BB8();
    switch (p->mode) {
    case 1:
        p->mode = 0;
        break;
    case 2:
        func_00502520(descriptor);
        break;
    case 0:
        func_004D2D48();
        break;
    }
    if (p->flags & 1)
        func_004D2AD0();
    if (p->flags & 2)
        func_004D2B10();
    func_004A2468(p->list);
    if (p->flags & 4)
        func_004D2C08();
}

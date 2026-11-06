#include "common.h"
typedef struct {
    s32 mode, selection, flags;
    char rest[0x58];
} State;
extern State D_0030EAA0[];
extern s32 func_00506BB8(void), func_004981D8(s32 *, s32, s32 (*)(s32)), func_00498280(s32 *, s32, s32 (*)(s32)), func_004CCF58(s32);
extern void func_004CCFA0(s32), func_004CCFE8(s32), func_004985F0(s32);
void func_004CD188(s32 mode)
{
    State *p = D_0030EAA0 + func_00506BB8();
    if (p->selection >= 0) {
        s32 found;
        func_004CCFA0(p->selection);
        switch (mode) {
        case 0:
            p->selection--;
            found = func_004981D8(&p->selection, 12, func_004CCF58);
            break;
        case 1:
            p->selection++;
            found = func_00498280(&p->selection, 12, func_004CCF58);
            break;
        case 3:
            found = func_00498280(&p->selection, 12, func_004CCF58);
            break;
        case 2:
            found = func_004981D8(&p->selection, 12, func_004CCF58);
            break;
        default:
            found = 0;
            break;
        }
        if (found) {
            func_004CCFE8(p->selection);
            func_004985F0(15);
            p->flags |= 1;
        }
    }
}

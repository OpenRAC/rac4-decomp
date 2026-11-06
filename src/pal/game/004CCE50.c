#include "common.h"
typedef struct {
    s32 mode, selection, flags, handle;
    u8 tail[0x54];
} State;
extern State D_0030EAA0[];
extern u8 D_001CDE70[];
extern s32 D_00221A20;
extern s32 func_00506BB8(void), func_004A2798(s32 *, s32), func_005062D0(s32, const char *), func_004CDC40(s32), func_0049A9D8(const void *, s32), func_005071B8(s32, s32);
extern const char *func_004CDA88(s32), *func_004CD8A0(s32);
extern void func_0049AA18(s32);
void func_004CCE50(void)
{
    State *p = D_0030EAA0 + func_00506BB8();
    if (p->selection >= 0) {
        s32 handle;
        u8 *icon;
        handle = func_004A2798(&D_00221A20, 0x25);
        func_005062D0(handle, func_004CDA88(p->selection));
        handle = func_004A2798(&D_00221A20, 0x26);
        func_005062D0(handle, func_004CD8A0(p->selection));
        icon = D_001CDE70 + func_004CDC40(p->selection) * 8;
        if (p->handle) {
            func_0049AA18(p->handle);
            p->handle = 0;
        }
        p->handle = func_0049A9D8(icon, -1);
        func_005071B8(func_004A2798(&D_00221A20, 15), p->handle);
        p->flags &= ~1;
    }
}

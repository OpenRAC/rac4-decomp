#include "common.h"
typedef struct State {
    s32 unk, mode;
    f32 start, current;
    u8 pad10[8];
    u32 value;
    u32 pad1C;
    f32 target;
    u8 selected, pending;
    u8 pad26[10];
    f32 active;
    s32 extra;
} State;
extern State D_00309940;
extern s32 D_00221858;
extern void func_004B6280(void), func_004B6028(void), func_004B6140(void);
extern s32 func_004A2798(s32 *, s32), func_00506590(s32, u32);
void func_004B5D38(void)
{
    func_004B6280();
    {
        State *s = &D_00309940;
        s32 *handles = &D_00221858;
        s->active = 0;
        s->current = s->start;
        s->target = (f32)s->selected;
        func_00506590(func_004A2798(handles, 6), s->value);
        func_004B6028();
        func_004B6140();
        if (s->pending)
            s->mode = 2;
        else
            s->mode = 1;
    }
}

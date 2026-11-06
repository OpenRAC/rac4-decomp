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
extern State D_00309840;
extern s32 D_00221758;
extern void func_004B5390(void), func_004B5138(void), func_004B5250(void);
extern s32 func_004A1A60(s32 *, s32), func_005054F8(s32, u32);
void func_004B4E48(void)
{
    func_004B5390();
    {
        State *s = &D_00309840;
        s32 *handles = &D_00221758;
        s->active = 0;
        s->current = s->start;
        s->target = (f32)s->selected;
        func_005054F8(func_004A1A60(handles, 6), s->value);
        func_004B5138();
        func_004B5250();
        if (s->pending)
            s->mode = 2;
        else
            s->mode = 1;
    }
}

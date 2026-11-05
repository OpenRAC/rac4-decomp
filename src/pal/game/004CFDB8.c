#include "common.h"
typedef struct List {
    u8 pad[0x50];
    s32 count;
    u8 end[0x18];
} List;
typedef struct State {
    u8 pad[8];
    u32 flags;
    u8 padC[0xF84];
    List list;
    u8 end[0x40];
} State;
extern u8 D_0030F820[];
extern s32 func_00506BB8(void), func_004E3138(s32, s32, void *);
extern void func_004A2048(List *), func_004A2090(List *);
extern s32 func_004E17B8(void);
static inline s32 count(List *p)
{
    return p->count;
}
void func_004CFDB8(s32 next)
{
    State *s = (State *)((u32)D_0030F820 + (u32)func_00506BB8() * 0x103C);
    if (count(&s->list) >= 2) {
        if (next)
            func_004A2090(&s->list);
        else
            func_004A2048(&s->list);
        func_004E3138(0, 0, 0);
        func_004E17B8();
        s->flags |= 6;
    }
}

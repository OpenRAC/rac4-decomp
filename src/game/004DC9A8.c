#include "common.h"
typedef struct Obj {
    u8 pad[0xF8];
    s32 unkF8;
} Obj;
typedef struct State {
    u8 pad[0x15D];
    u8 unk15D;
    u8 pad15E[2];
    f32 unk160;
    u8 tail[4];
} State;
typedef struct Slot {
    u8 pad[8];
    Obj *obj;
    u8 tail[0x18];
} Slot;
extern State D_00322FC8[];
extern Slot D_00323130[];
extern s32 func_00505B20(void);
extern void func_0046E728(Obj *);
extern void func_0046EDD8(Obj *);
extern void func_004706F0(Obj *);
void func_004DC9A8(s32 arg0)
{
    State *s = &D_00322FC8[func_00505B20()];
    f32 lim = 0.09817477f;
    f32 step = 0.024543693f;
    Obj *o;
    s32 i;
    switch (arg0) {
    case 1:
        s->unk160 += step;
        if (lim < s->unk160)
            s->unk160 = lim;
        break;
    case 2:
        s->unk160 -= step;
        if (s->unk160 < -lim)
            s->unk160 = -lim;
        break;
    case 3:
        s->unk160 = 0.0f;
        break;
    case 4:
        s->unk15D = 1;
        s->unk160 = 0.0f;
        for (i = 0; i < 6; i++) {
            o = D_00323130[i].obj;
            if (o != 0) {
                o->unkF8 = 0;
                func_0046E728(o);
                func_0046EDD8(o);
                func_004706F0(o);
            }
        }
        break;
    }
}

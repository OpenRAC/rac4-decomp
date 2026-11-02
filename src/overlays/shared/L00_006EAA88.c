#include "common.h"
extern s32 D_00171E00[];
extern s32 D_00171E78[];
extern s32 D_00171EF0[];
extern s32 D_00172160[];
typedef struct { char pad[0x4c]; s32 time; s32 data[12]; } Obj;
typedef struct { char pad[4]; Obj *obj; } Link;
typedef struct { char pad[0x2f10]; s32 index; char pad2[0x14]; Link *link; } Arg;
void func_L00_006EAA88(Arg *arg) {
    s32 index = arg->index;
    Obj *obj = arg->link->obj;
    s32 *a = &D_00171E00[index];
    s32 *b = &D_00171E78[index];
    s32 *c = &D_00171EF0[index];
    s32 *out = &obj->data[8];
    s32 i = 2;
    do {
        *(s32 *)((char *)out - 24) = *a; a += 10;
        *(s32 *)((char *)out - 12) = *b; b += 10;
        out[0] = *c; c += 10;
        out++;
    } while (--i >= 0);
    if (obj->time < D_00172160[0x218/4] - 0x4b0)
        obj->time = D_00172160[0x218/4];
}

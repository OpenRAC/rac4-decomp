#include "common.h"
extern s32 D_00171E80[];
extern s32 D_00171EF8[];
extern s32 D_00171F70[];
#include "pal/profile_001721E0.h"
typedef struct { char pad[0x4c]; s32 time; s32 data[12]; } Obj;
typedef struct { char pad[4]; Obj *obj; } Link;
typedef struct { char pad[0x2f10]; s32 index; char pad2[0x14]; Link *link; } Arg;
void func_L00_006EE648(Arg *arg) {
    s32 index = arg->index;
    Obj *obj = arg->link->obj;
    s32 *a = &D_00171E80[index];
    s32 *b = &D_00171EF8[index];
    s32 *c = &D_00171F70[index];
    s32 *out = &obj->data[8];
    s32 i = 2;
    do {
        *(s32 *)((char *)out - 24) = *a; a += 10;
        *(s32 *)((char *)out - 12) = *b; b += 10;
        out[0] = *c; c += 10;
        out++;
    } while (--i >= 0);
    if (obj->time < (s32)(D_001721E0.region20.words.f218 - 0x4B0U))
        obj->time = (s32)D_001721E0.region20.words.f218;
}

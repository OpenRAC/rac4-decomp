/* Not matching yet: BYTES 8/716 (tools/try_func.py func_004DB7B8 --diff). Not part of the build. */
#include "common.h"
typedef struct Model {
    u8 pad[0x10];
    u8 count;
} Model;
typedef struct Res {
    u8 pad[0x48];
    Model *models[1];
} Res;
typedef struct Obj {
    u8 pad[0x24];
    Res *res;
    u8 pad28[0x1C];
    f32 frame;
    u8 pad48[0x18];
    s32 color;
    u8 pad64[0x94];
    f32 scale;
} Obj;
typedef struct Anim {
    u8 pad[0x13C0];
    s32 seq[4];
    s32 total;
    s32 cur;
    s32 n;
    s32 off;
    u8 flip;
} Anim;
extern Anim D_00321B98;
extern s32 D_002211CC;
extern f32 func_00453940(f32);
extern Obj *func_0046D820(s32 arg0);
extern void func_0046E728(Obj *);
extern void func_0046EDD8(Obj *);
extern void func_0046F2B0(Obj *, Model *, s32, f32, s32);
extern void func_004706F0(Obj *);
extern s32 func_00472560(s32 a0);

void func_004DB7B8(void)
{
    Anim *a = &D_00321B98;
    s32 changed = 0;
    Obj *o;
    s32 i;

    o = func_0046D820(0);
    if (o != 0) {
        s32 v = func_00453940((f32)((D_002211CC & 0x3F) - 0x20) * 0.09817477f) * 32.0f + 96.0f;
        *(s32 *)((u8 *)o + 0x60) = (v << 24) | (v << 16) | (v << 8) | 0x80;
        o->scale = func_00453940((f32)((D_002211CC & 0x1FF) - 0x100) * 0.012271847f) * 0.5f;
        if ((s32)o->frame + 1 >= a->total - a->off) {
            i = func_00472560(a->n);
            if (i == a->cur) {
                if (a->flip == 0) {
                    a->flip = 1;
                } else {
                    do {
                        i = func_00472560(a->n);
                    } while (i == a->cur);
                    a->flip = 0;
                }
            }
            a->cur = i;
            a->total = o->res->models[i]->count;
            changed = 1;
            func_0046F2B0(o, o->res->models[a->seq[i]], a->seq[i], 0.0f, a->off);
        }
        func_0046E728(o);
        func_0046EDD8(o);
        func_004706F0(o);
    }
    o = func_0046D820(1);
    if (o != 0) {
        s32 v = func_00453940((f32)((D_002211CC & 0x3F) - 0x20) * 0.09817477f) * 32.0f + 96.0f;
        *(s32 *)((u8 *)o + 0x60) = (v << 24) | (v << 16) | (v << 8) | 0x80;
        o->scale = func_00453940((f32)((D_002211CC & 0x1FF) - 0x100) * 0.012271847f) * 0.5f;
        if (changed) {
            func_0046F2B0(o, o->res->models[a->seq[a->cur]], a->seq[a->cur], 0.0f, a->off);
        }
        func_0046E728(o);
        func_0046EDD8(o);
        func_004706F0(o);
    }
}

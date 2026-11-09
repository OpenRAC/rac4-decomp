/* cflags: -ffast-math */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad04[3];
    u8 flags;
    u8 state;
    u8 prev;
    u8 pad0A[0x0E];
    u32 unk18;
    u8 pad1C[8];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    u8 pad30[0x20];
} Rec;

extern Rec D_00355DC0[];

extern void func_001587E0(s32 arg0);
extern void func_00158920(s32 arg0, void *arg1, u64 arg2);
extern void func_001592D8(s32 arg0);
extern void func_00159308(s32 arg0);
extern void func_00159398(s32 arg0, void *arg1, u64 arg2);
extern void func_0048A950(void *arg0);
extern s32 func_0048AA30(s32 arg0, Rec *arg1);
extern void func_0048AC48(s32 arg0, Rec *arg1);
extern void func_0048AC68(s32 arg0, Rec *arg1);
extern void func_0048AF30(void);
extern void func_0048AF98(void);

void func_0048A498(s32 arg0, f32 dt) {
    s32 i;
    Rec *s;
    f32 t;

    for (i = 0; i < 3; i++) {
        s = &D_00355DC0[i];
        if (s->state == 1) {
            if ((s->flags & 8) || !func_0048AA30(arg0, s)) {
                func_0048A950(s);
                continue;
            }
            s->state = 2;
        }
        if (s->state == 2 && (s->flags & 8)) {
            func_0048A950(s);
            continue;
        }
        if (s->state == 3) {
            if (s->flags & 8) {
                s->state = 7;
                s->flags &= ~8;
            } else {
                func_00159398(s->unk0, func_0048AF30, s->unk18);
            }
        }
        if (s->state == 4) {
            if (s->flags & 8) {
                s->state = 7;
                s->flags &= ~8;
            } else if (s->flags & 2) {
                s->prev = s->state;
                s->flags &= ~2;
                s->state = 6;
            } else if (s->flags & 1) {
                func_0048AC68(arg0, s);
                func_0048AC48(arg0, s);
                s->state = 5;
                s->flags &= ~1;
            }
        }
        if (s->state == 5) {
            if (s->flags & 8) {
                s->state = 7;
                s->flags &= ~8;
            } else if (s->flags & 2) {
                func_001592D8(s->unk0);
                s->prev = s->state;
                s->state = 6;
                s->flags &= ~2;
            } else {
                func_0048AC68(arg0, s);
            }
            func_00158920(s->unk0, func_0048AF98, s->unk18);
        }
        if (s->state == 7) {
            if (s->unk28 > 0.0f) {
                t = s->unk28 - dt;
                t = (t > 0.0f) ? t : 0.0f;
                s->unk28 = t;
                s->unk24 = t * s->unk2C;
                func_0048AC68(arg0, s);
            } else {
                func_001587E0(s->unk0);
            }
            func_00158920(s->unk0, func_0048AF98, s->unk18);
        }
        if (s->state == 6) {
            if (s->flags & 8) {
                s->state = 7;
                s->flags &= ~8;
            } else if (s->flags & 4) {
                if (s->prev == 5) {
                    func_00159308(s->unk0);
                }
                s->state = s->prev;
                s->flags &= ~4;
            }
        }
    }
}

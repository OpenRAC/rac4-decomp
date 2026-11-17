/* Not matching yet: BYTES 30/1028 (retail's size, 30 differing bytes; the prologue is exact — the
   residue is the delayed-branch fill (our bc1tl+abs.s vs retail's bc1t+nop) and the load/sub
   schedule of the dx/dy pair). Not part of the build. */

extern void func_L00_0071B8E8(void *, s32, s32);

typedef void (*Fn)(void *self, f32 *a, f32 *b);

typedef struct {
    char pad[0x34];
    Fn fn;
} Vt;

typedef struct {
    char pad[0x58];
    Vt *vt;
} Obj;

typedef struct {
    u8 pad0[0xB0];
    Obj *unkB0[(0x230 - 0xB0) / 4];
    u32 unk230;
} Type0;

void func_L00_007412D0(Type0 *arg0, s32 arg1, s32 arg2) {
    Obj *o;
    f32 sp0, sp4, sp8, spC, sp10, sp14;
    f32 f20, f21, f22, f23;
    f32 dx, dy;
    s32 s1;
    s32 s0;

    if (arg0->unk230 >= 0x35) {
        func_L00_0071B8E8(arg0, 6, 0);
        return;
    }
    if (arg0->unk230 == 0x10 && arg1 < 0) {
        func_L00_0071B8E8(arg0, 0x1A, 0);
        return;
    }
    s1 = arg0->unk230;
    f20 = 1.0f;
    f21 = 1.0f;
    f22 = 0.0f;
    f23 = 0.001f;
    o = arg0->unkB0[s1];
    o->vt->fn(o, &sp0, &sp4);
    for (s0 = 0; s0 < 0x35; s0++) {
        if (s0 == arg0->unk230) continue;
        o = arg0->unkB0[s0];
        o->vt->fn(o, &sp8, &spC);
        dy = spC - sp4;
        dx = sp8 - sp0;
        if (arg1 < 0) {
            f32 ndy;
            if (!(dy < f22)) continue;
            ndy = -dy;
            if (!(ndy <= f20)) continue;
            dx = __builtin_fabsf(dx);
            if (dx < f21 || ndy < f20) {
                if (!(dx < __builtin_fabsf(dy))) continue;
                f21 = dx;
                f20 = ndy;
                s1 = s0;
            }
        } else if (arg1 > 0) {
            if (!(dy > f22)) continue;
            if (!(dy <= f20)) continue;
            dx = __builtin_fabsf(dx);
            if (dx < f21 || dy < f20) {
                if (!(dx < __builtin_fabsf(dy))) continue;
                f21 = dx;
                f20 = dy;
                s1 = s0;
            }
        } else if (arg2 < 0) {
            f32 ndx = -dx;
            f32 ady;
            if (!(ndx < f21)) continue;
            if (!(dx < f22)) continue;
            ady = __builtin_fabsf(dy);
            if (!(ady < __builtin_fabsf(dx))) continue;
            if (!(ady < f23)) continue;
            f21 = ndx;
            f20 = dy;
            s1 = s0;
        } else if (arg2 > 0) {
            f32 ady;
            if (!(dx < f21)) continue;
            if (!(dx > f22)) continue;
            ady = __builtin_fabsf(dy);
            if (!(ady < __builtin_fabsf(dx))) continue;
            if (!(ady < f23)) continue;
            f21 = dx;
            f20 = dy;
            s1 = s0;
        }
    }
    if (s1 == arg0->unk230) {
        f20 = 0.0f;
        f21 = 0.0f;
        f22 = 0.001f;
        for (s0 = 0; s0 < 0x35; s0++) {
            if (s0 == arg0->unk230) continue;
            o = arg0->unkB0[s0];
            o->vt->fn(o, &sp10, &sp14);
            dy = sp14 - sp4;
            dx = sp10 - sp0;
            if (arg1 < 0) {
                if (!(f20 <= dy)) continue;
                dx = __builtin_fabsf(dx);
                if (dx < f21 || f20 < dy) {
                    f21 = dx;
                    f20 = dy;
                    s1 = s0;
                }
            } else if (arg1 > 0) {
                dy = -dy;
                if (!(f20 <= dy)) continue;
                dx = __builtin_fabsf(dx);
                if (dx < f21 || f20 < dy) {
                    f21 = dx;
                    f20 = dy;
                    s1 = s0;
                }
            } else if (arg2 < 0) {
                if (!(f21 < dx)) continue;
                if (!(__builtin_fabsf(dy) < f22)) continue;
                f21 = dx;
                f20 = dy;
                s1 = s0;
            } else if (arg2 > 0) {
                dx = -dx;
                if (!(f21 < dx)) continue;
                if (!(__builtin_fabsf(dy) < f22)) continue;
                f21 = dx;
                f20 = dy;
                s1 = s0;
            }
        }
    }
    func_L00_0071B8E8(arg0, s1, 0);
}

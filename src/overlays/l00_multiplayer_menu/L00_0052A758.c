/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u64 *p;
    s32 n;
    s32 pad[6];
} Buf;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
} Obj;

extern void func_00538180(Buf *);
extern s32 func_00538D50(void);
extern void func_L00_004F84C8(int, int, int, int, int);
extern s32 func_L00_00520E90(void);
extern void func_L00_00537BB0(Buf *, Buf *, s32);
extern s32 func_L00_00537CE8(void *, void *, s32, void *);
extern void *func_L00_00537D20(void *, Buf *, s32, void *);
extern s32 func_L00_00537F68(s32);
extern void func_L00_00537FB0(void *);
extern void *func_L00_00538190(void);
extern void *func_L00_005381D8(void);
extern void func_L00_00538258(void *);
extern s32 func_L00_005387E0(Buf *, s32);
extern s32 func_L00_0053AAB0(void *, s32, Buf *, s32, void *, s32);
extern s32 func_L00_0053B9C0(s32, s32, void *);
extern s32 func_L00_0053BB68(Buf *, s32, s32, s32, s32);

// Build a result object and its companion from obj's settings, replacing *out_r and *out_m.
s32 func_L00_0052A758(Obj *obj, void *ctx_in, void **out_r, void **out_m) {
    Buf buf;
    s32 ok = 0;
    void *ctx;
    void *r = 0;
    void *m = 0;
    s32 t;
    s32 seed;

    if (ctx_in == 0) {
        ctx = func_L00_005381D8();
        if (ctx == 0) goto err;
    } else {
        ctx = ctx_in;
    }
    if (obj->unk2C == 0 && (obj->unk28 & 1)) {
        t = func_00538D50();
        obj->unk2C = t;
        if (t != 0) {
            if (!func_L00_0053B9C0(t, obj->unkC, ctx)) goto err;
        }
    }
    r = 0;
    func_00538180(&buf);
    m = func_L00_00538190();
    if (m == 0) goto err;
    for (;;) {
        seed = func_L00_00520E90();
        if (!func_L00_0053BB68(&buf, seed, func_L00_00537F68(obj->unk10), 1, 0)) goto err;
        if (func_L00_005387E0(&buf, obj->unk10) >= 0) {
            func_L00_00537BB0(&buf, &buf, obj->unk10);
        }
        if (buf.n != 0 && (buf.n != 1 || *buf.p != 0)) break;
    }
    if (!func_L00_0053AAB0(m, obj->unk14, &buf, obj->unkC, ctx, obj->unk2C)) goto err;
    if (!func_L00_00537CE8(m, m, obj->unk10, ctx)) goto err;
    r = func_L00_00537D20(0, &buf, obj->unk10, ctx);
    if (r == 0) goto err;
    if (*out_m != 0) func_L00_00537FB0(*out_m);
    if (*out_r != 0) func_L00_00537FB0(*out_r);
    *out_m = m;
    ok = 1;
    m = 0;
    *out_r = r;
    r = 0;
    goto done;
err:
    func_L00_004F84C8(0xA, 0x6A, 0x803, 0, 0);
done:
    if (ctx_in == 0) func_L00_00538258(ctx);
    if (r != 0) func_L00_00537FB0(r);
    if (m != 0) func_L00_00537FB0(m);
    func_L00_00537FB0(&buf);
    return ok;
}

/* Not matching yet: BYTES 27/332 (tools/try_func.py func_0050D130 --diff). Not part of the build. */
typedef struct {
    f32 f0[6];
} Type2;

typedef struct Type3 Type3;

typedef struct {
    char pad0[0x18];
    void (*f18)(Type3 *, ...);
} Type4;

struct Type3 {
    char pad0[0x8];
    Type4 *f8;
    s32 fC;
};

typedef struct {
    char pad0[0x40];
    Type3 *f40[105];
    Type3 *f1E4;
    s32 f1E8;
    s32 pad1EC;
    f32 f1F0;
    f32 f1F4;
    f32 f1F8;
    f32 f1FC;
} Type1;

// Remap a box through the owner's scale/offset and dispatch it to the active child or all enabled children.
s32 func_0050D130(Type1 *arg0, Type2 *arg1) {
    Type2 box;
    f32 x0;
    f32 y0;
    f32 dx;
    f32 dy;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 flags;
    Type3 *obj;
    s32 i;

    x0 = arg1->f0[0];
    y0 = arg1->f0[1];
    dx = arg1->f0[2] - x0;
    dy = arg1->f0[3] - y0;
    a = dx * arg0->f1F0 + x0;
    b = dy * arg0->f1F4 + y0;
    c = dx * arg0->f1F8 + x0;
    d = dy * arg0->f1FC + y0;
    box = *arg1;
    box.f0[0] = a;
    box.f0[1] = b;
    box.f0[2] = c;
    box.f0[3] = d;
    obj = arg0->f1E4;
    if (obj != 0) {
        obj->f8->f18(obj, &box, arg0->f40);
    } else {
        for (i = 0; i < arg0->f1E8; i++) {
            obj = arg0->f40[i];
            flags = obj->fC;
            if (flags & 1) {
                if (!(flags & 0x10000)) {
                    obj->f8->f18(obj, arg1);
                }
            }
        }
    }
    return 1;
}

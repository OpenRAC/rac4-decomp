/* Not matching yet: BYTES 10/840 (tools/try_func.py func_00540308 --diff). Not part of the build. */
typedef struct Type1 {
    u32 f0;
    s32 f4;
    s32 f8;
} Type1;

typedef struct Type2 {
    u8 pad0[0x14];
    void (*f14)(void *, void *);
    void (*f18)(void *, void *);
} Type2;

typedef struct Type3 {
    u8 pad0[0x14];
    Type2 *f14;
    u8 pad18[0x44 - 0x18];
    s32 f44;
} Type3;

typedef struct Type4 {
    s32 f0;
    s32 f4;
    u8 pad8[0x2C - 0x8];
    u8 f2C;
    u8 pad2D[0x34 - 0x2D];
    s32 f34;
    u8 pad38[0x44 - 0x38];
    s32 f44;
    s32 f48;
    u8 pad4C[0x50 - 0x4C];
    u8 f50;
    u8 f51;
    u8 pad52[0x54 - 0x52];
} Type4;

extern Type3 *func_0053FCA0(s16 a, s16 b, s32 c, s32 d, s32 e);
extern Type1 *func_00511060(s32 id);
extern void func_0053CB20(void *b, void *a, s32 n);
extern void func_00540700(void *arg0, s32 arg1, s32 arg2);
extern void func_00540770(void *handle, s32 value_in, s32 param);
extern void func_005407D8(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern u32 D_00220B90;
extern s32 D_00220B88;
extern Type4 D_349DF8[];

// Decodes one message from the buffer by its type nibble and applies it to the object it names.
void func_00540308(void *arg0, u32 *buf)
{
    switch (*buf & 0xF) {
    case 0: {
        s32 a;
        s16 b;
        u16 c;
        s32 d;
        Type3 *obj;
        Type2 *o;
        func_0053CB20(buf, &a, 4);
        func_0053CB20(buf, &b, 2);
        func_0053CB20(buf, &c, 2);
        func_0053CB20(buf, &d, 4);
        obj = func_0053FCA0(b, c, a, 0, 1);
        obj->f44 = (*buf >> 10) & 0xF;
        obj->f14->f14(obj, buf);
        o = (Type2 *)func_00511060(d);
        if (o != 0) {
            ((Type3 *)o)->f14->f18(o, obj);
        }
        break;
    }
    case 1: {
        s32 id;
        u8 a;
        u8 b;
        Type1 *p;
        func_0053CB20(buf, &id, 4);
        func_0053CB20(buf, &a, 1);
        func_0053CB20(buf, &b, 1);
        p = func_00511060(id);
        if (p != 0 && ((p->f0 & D_00220B90) >> D_00220B88) == 6 && p->f8 != 2) {
            func_00540700(p, a, b);
        }
        break;
    }
    case 2: {
        s32 id;
        u8 a;
        u8 b;
        Type1 *p;
        func_0053CB20(buf, &id, 4);
        func_0053CB20(buf, &a, 1);
        func_0053CB20(buf, &b, 1);
        p = func_00511060(id);
        if (p != 0 && ((p->f0 & D_00220B90) >> D_00220B88) == 6 && p->f8 != 2) {
            func_00540770(p, a, b);
        }
        break;
    }
    case 3: {
        s32 id;
        u8 a;
        u8 b;
        u8 c;
        Type1 *p;
        func_0053CB20(buf, &id, 4);
        func_0053CB20(buf, &a, 1);
        func_0053CB20(buf, &b, 1);
        func_0053CB20(buf, &c, 1);
        p = func_00511060(id);
        if (p != 0 && ((p->f0 & D_00220B90) >> D_00220B88) == 6 && p->f8 != 2) {
            func_005407D8(p, a, b, c);
        }
        break;
    }
    case 4: {
        u8 a;
        u8 b;
        Type4 *e;
        s32 i;
        func_0053CB20(buf, &a, 1);
        func_0053CB20(buf, &b, 1);
        for (i = 0; i < 512; i++) {
            e = &D_349DF8[i];
            if (e->f2C != 0) {
                if (e->f44 == a) {
                    e->f4 = -1;
                    e->f34 = -1;
                    e->f48 = -1;
                    e->f50 = 0;
                    e->f51 = 1;
                    e->f44 = b;
                } else if (e->f48 == a) {
                    e->f4 = -1;
                    e->f34 = -1;
                    e->f48 = -1;
                }
            }
        }
        break;
    }
    }
}

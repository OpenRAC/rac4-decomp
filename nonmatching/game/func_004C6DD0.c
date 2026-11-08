/* Not matching yet: BYTES 17/752 (tools/try_func.py func_004C6DD0 --diff). Not part of the build. */
typedef struct {
    s32 f0;
    s32 f4;
} Type4;

typedef struct {
    s32 f0;
    s32 f4;
    Type4 *f8;
    s32 fC;
    s32 f10;
    s32 f14;
} Type3;

typedef struct {
    u8 pad0[0x34];
    Type3 *f34;
    u8 pad38[0x18];
    s32 f50;
    s32 f54;
} Type6;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0xAB4 - 0x14];
    Type6 fAB4;
    u8 padB0C[0x20];
    s32 fB2C;
} Type2;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} Type5;

extern s32 func_0045E038(s32);
extern s32 func_0046B330(s32, s32);
extern s32 func_0046B3B8(s32, s32);
extern void func_004979A8(void *, s32, s32);
extern void func_00498C98(void *arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004FBFD0(void *dst, s32 a, s32 b, s32 force);
extern void func_00504F68(s32, s32);
extern s32 func_00505238(u32, const char *);
extern void func_00505328(s32, s32);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B20(void);
extern void *func_0054A998(s32 arg0);
extern s32 func_0054AB08(s32 arg0, s32 arg1);

extern s32 D_0021FA08[];
extern s32 D_002218C8;
extern char D_0030B900[];
extern char D_0030B930[];
extern Type2 D_0030B9D8[];

static inline Type3 *sel(Type6 *s)
{
    if (s->f54 < 0)
        return 0;
    return &s->f34[s->f54];
}

/* fills a menu page from the selected entry, then clears flag 2 */
void func_004C6DD0(void)
{
    s32 id = func_00505B20();
    Type2 *p = &D_0030B9D8[id];
    Type5 buf[2];

    Type6 *s = &p->fAB4;

    if (s->f50 > 0) {
        Type3 *e;
        Type4 *q;
        s32 i;
        e = sel(s);
        q = e->f8;
        i = 0;
        if (q != 0) {
            s32 *ids = D_0021FA08;
            s32 *r;
            s32 a, b, n;
            r = func_0054A998(func_0054AB08(p->fB2C, q->f4));
            func_00505238(func_004A1A60(&D_002218C8, 0x30), (const char *)func_0045E038(r[3]));
            func_00504F68(func_004A1A60(&D_002218C8, 0x30), 1);
            a = func_0046B330(p->fB2C, q->f4);
            b = func_0046B3B8(p->fB2C, q->f4);
            func_004979A8(D_0030B900, a, 0);
            func_004979A8(D_0030B930, b, 0);
            func_00505238(func_004A1A60(&D_002218C8, 0x28), D_0030B900);
            func_00505238(func_004A1A60(&D_002218C8, 0x20), D_0030B930);
            func_00505238(func_004A1A60(&D_002218C8, 0x31), (const char *)func_0045E038(0x300F));
            func_00505238(func_004A1A60(&D_002218C8, 0x32), (const char *)func_0045E038(0x3010));
            func_00504F68(func_004A1A60(&D_002218C8, 0x28), 1);
            func_00504F68(func_004A1A60(&D_002218C8, 0x20), 1);
            n = func_004FBFD0(buf, p->fB2C, q->f4, 0);
            for (i = 0; i < 2; i++) {
                func_00498C98(&buf[i]);
                func_00504F68(func_004A1A60(&D_002218C8, *ids), i < n);
                func_005054F8(func_004A1A60(&D_002218C8, *ids), buf[i].f8);
                func_00505328(func_004A1A60(&D_002218C8, *ids), buf[i].fC);
                ids++;
            }
        }
    }
    D_0030B9D8[id].f10 &= ~2;
}

/* Not matching yet: BYTES 45/160 (tools/try_func.py func_01ED8338 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G8 -mno-split-addresses */
extern void func_0011A518(void *, s32, s32);
extern s32 func_01ED78C8(void *, s32, void *);
extern void func_01ED8278(void *, s32, s32, s32);

extern s8 D_00169CE0[];
extern s32 D_1BC948;
extern s32 D_1BCB40;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
} Rec;

extern Rec D_1BD290;

void func_01ED8338(void)
{
    s32 buf[0xC];
    Rec *p;

    p = &D_1BD290;
    if (p->f10 == 0) {
        return;
    }
    func_0011A518(buf, 0, 0x30);
    func_01ED78C8(D_00169CE0, 0x8E, buf);
    p->f18 = 1;
    buf[11] = p->f10;
    buf[6] = p->f0;
    buf[7] = p->f4;
    buf[8] = p->f8;
    buf[9] = p->fC;
    buf[10] = p->f14;
    func_01ED8278(buf, D_1BCB40, D_1BC948, p->f8);
}

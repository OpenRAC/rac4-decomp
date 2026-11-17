/* Not matching yet: BYTES 35/192 (@ee29, first at retail size; was SIZE 176/192). Not part of the build. */
/* cflags: @ee29  */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} E;

typedef struct S2 {
    s32 f0;
    struct S2 *f4;
} S2;

typedef struct S1 {
    s32 f0;
    S2 *f4;
} S1;

extern E D_004A0640[];
extern S1 *D_004A1888;
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern S2 *func_L00_004F8BE0(S1 *, s32);

typedef struct {
    s32 f0;
    void *f4;
    char _p8[0x10 - 0x8];
    s32 f10;
    void *f14;
    s32 f18;
    char _p1C[0x30 - 0x1C];
} Req;

s32 func_L00_0051C9C8(u32 arg0) {
    Req local;
    S2 *r;

    if (arg0 < 0x8C) {
        if (arg0 == 0 || D_004A0640[arg0].f8 != 0) {
            return D_004A0640[arg0].f4;
        }
    } else {
        if (D_004A1888 == NULL) {
            return 0;
        }
        local.f0 = 3;
        local.f4 = &local.f10;
        local.f18 = arg0;
        r = func_L00_004F8BE0(D_004A1888, (s32)&local);
        if (r != NULL) {
            return r->f4->f4;
        }
    }
    func_L00_004F84C8(8, 0x66, 0x65, 0, 0);
    return 0;
}

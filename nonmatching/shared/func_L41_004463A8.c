/* Not matching yet: BYTES 21/112 (tools/try_func.py func_L41_004463A8 --diff). Not part of the build. */
typedef struct {
    /*0x00*/ s32 f00;
    /*0x04*/ s32 f04;
    /*0x08*/ s32 f08;
    /*0x0C*/ s32 f0C;
    /*0x10*/ s32 f10;
    /*0x14*/ s32 f14;
    /*0x18*/ s32 f18;
    /*0x1C*/ s32 f1C;
    /*0x20*/ u8 pad20[0x50];
    /*0x70*/ s32 f70;
    /*0x74*/ u8 f74;
    /*0x75*/ u8 pad75;
    /*0x76*/ s16 f76;
    /*0x78*/ s32 f78;
    /*0x7C*/ s32 f7C;
    /*0x80*/ s32 f80;
    /*0x84*/ s32 f84;
    /*0x88*/ s32 f88;
    /*0x8C*/ s32 f8C;
} Obj;

typedef struct {
    u8 pad[0xAC];
    Obj *fAC;
} Arg;

typedef struct {
    u8 pad[0x50];
    s32 f50;
    s32 f54;
} Glob;

extern Glob D_003980C8;
extern s32 D_002204B0;

void func_L41_004463A8(Arg *arg0) {
    s32 g = D_002204B0;
    Obj *p = arg0->fAC;

    p->f00 = 0;
    p->f04 = 0;
    p->f08 = D_003980C8.f50;
    p->f0C = D_003980C8.f54;
    p->f74 = 0xA;
    p->f78 = 0x1E;
    p->f80 = -1;
    p->f8C = g;
    p->f88 = 0;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1C = 0;
    p->f7C = 0;
    p->f76 = 0;
    p->f84 = 0;
    p->f70 = -1;
}

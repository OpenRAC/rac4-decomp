#include "common.h"

typedef struct Chan {
    u8 pad0[0x10];
} Chan;

typedef struct Astrm {
    s32 x0;
    s16 x4;
    s16 x6;
} Astrm;

typedef struct Args {
    s32 x0;
    u8 pad4[0xC];
    s32 x10;
    u8 pad14[0x4C];
    s32 x60;
    s32 x64;
    s32 x68;
    void *x6C;
    s32 x70;
    u8 pad74[0xC];
} Args;

extern u8 D_0020BA40[];
extern u8 D_0020BA90[];
extern u8 D_001C20C0[];
extern void func_00453E20(void *, s32, s32);
extern s32 func_00163A00(void);
extern void func_00126E20(s32);
extern s32 func_00159978(s32, s32, s32, void *);
extern void func_00127568(void *, void *);

static inline u8 *astrm(void) {
    return D_0020BA40;
}

// Astrm init
s32 func_00439E08(void) {
    Args r;
    u8 *s;
    Chan *ch;
    s32 i;
    u8 *g;

    s = astrm();
    func_00453E20(s, 0, 0x44);
    ((Astrm *)s)->x4 = -1;
    ((Astrm *)s)->x6 = -1;
    ch = (Chan *)s;
    for (i = 0; i < 3; i++, ch++) {
        *(s32 *)((u8 *)ch + 0x14) = (*(s32 *)((u8 *)ch + 0x14) & ~0xF00) | ((i & 0xF) << 8);
    }
    r.x64 = func_00163A00();
    g = D_001C20C0;
    r.x60 = *(s32 *)(g + 0x694) << 11;
    r.x10 = *(s32 *)(g + 0x690) + *(s32 *)(g + 0x64C);
    r.x68 = 0xC000;
    r.x70 = 3;
    r.x0 = 0;
    r.x6C = D_0020BA90;
    func_00126E20(0);
    if (func_00159978(0xBFE87362, 10, 0x80, &r) != 1) {
        return 0;
    }
    func_00127568(D_0020BA90, D_0020BA90 + 0x247);
    *(s32 *)astrm() |= 1;
    return 1;
}

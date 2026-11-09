#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u8 _p10[0x54];
} Type1;

typedef struct Type2 {
    s32 f0;
    s32 f4;
} Type2;

extern u32 func_00499CA0(void *descriptor, s32 sectorBase);
extern void func_00499CE0(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004CCA00(s32 arg0);
extern s32 func_004CCBE8(s32 arg0);
extern s32 func_004CCDA0(s32 arg0);
extern s32 func_00505238(u32, const char *);
extern s32 func_00505B20(void);
extern s32 func_00506120(u32 id, u32 value);
extern Type2 D_001CDDF0[];
extern s32 D_00221920;
extern Type1 D_0030EAA0[];

void func_004CBFB0(void) {
    Type1 *e = &D_0030EAA0[func_00505B20()];
    Type2 *d;

    if (e->f4 < 0) {
        return;
    }
    func_00505238(func_004A1A60(&D_00221920, 0x25), (const char *)func_004CCBE8(e->f4));
    func_00505238(func_004A1A60(&D_00221920, 0x26), (const char *)func_004CCA00(e->f4));
    d = &D_001CDDF0[func_004CCDA0(e->f4)];
    if (e->fC != 0) {
        func_00499CE0(e->fC);
        e->fC = 0;
    }
    e->fC = func_00499CA0(d, -1);
    func_00506120(func_004A1A60(&D_00221920, 0xF), e->fC);
    e->f8 &= ~1;
}

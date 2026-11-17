#include "common.h"

typedef struct {
    u8 pad0[0x120];
    f32 f120;
    f32 f124;
    u8 pad1[0x2E08 - 0x128];
    f32 f2E08;
    f32 f2E0C;
    u8 pad2[0x2E38 - 0x2E10];
    f32 f2E38;
    u8 pad3[0x2F00 - 0x2E3C];
    u8 *f2F00;
} Obj;

extern f32 func_L00_005BCEC8(f32, f32);
extern void func_L00_006BF048();
extern f32 func_L00_006BF860(void *, void *);
extern s32 D_0021E784;

// Runs func_L00_006BF048, then while D_0021E784 is 0 copies two floats from the 0x2F00 block into the object and stores three results; otherwise clears D_0021E784.
void func_L00_006EA528(Obj *o) {
    func_L00_006BF048(o);
    if (D_0021E784 != 0) {
        D_0021E784 = 0;
    } else {
        o->f120 = *(f32 *)(o->f2F00 + 0x108);
        o->f124 = -*(f32 *)(o->f2F00 + 0x10C);
        o->f2E38 = func_L00_006BF860(o, &o->f120);
        o->f2E08 = func_L00_006BF860(o, &o->f120);
        o->f2E0C = func_L00_005BCEC8(o->f120, o->f124);
    }
}

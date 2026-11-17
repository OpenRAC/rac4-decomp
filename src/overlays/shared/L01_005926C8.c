#include "common.h"

typedef struct Def {
    u8 pad0[6];
    u8 f6;
    u8 pad7[7];
    u8 fE;
    u8 fF;
    s32 f10;
    u8 pad14[0x2C];
    s32 f40;
} Def;

typedef struct Ent {
    u8 pad0[0x22];
    u8 f22;
    u8 pad23;
    Def *f24;
    u8 pad28[0xC];
    u16 f34;
    u8 pad36[0x20];
    u8 f56;
    u8 pad57[7];
    u8 f5E;
    u8 pad5F;
    s32 f60;
    u8 f64;
    u8 f65;
    u8 f66;
    u8 pad67[9];
    u8 f70;
    u8 pad71[5];
    u8 f76;
    u8 pad77[5];
    s32 f7C;
    u8 pad80[0x18];
    s32 f98;
    u8 pad9C[0x20];
    s16 fBC;
} Ent;

extern u8 D_26B590[];
extern Def *D_26AA40[];
extern void func_L00_005E4118(Ent *);
extern void func_L00_005E64B0(s32 to, s32 from, s32 copy_extra);
extern void func_L00_005E7538(void *, s32, f32);

/* Sets the entry's definition index and reloads its derived fields. */
s32 func_L01_005926C8(Ent *self, s32 arg1, s32 arg2) {
    if (self->fBC == arg1) {
        return 0;
    }
    self->fBC = arg1;
    self->f22 = D_26B590[(s16)arg1];
    self->f24 = D_26AA40[self->f22];
    self->f56 = 0xFF;
    func_L00_005E64B0(arg1, arg2, 0);
    func_L00_005E7538(self, 0, 0.0f);
    self->f64 = self->f24->fE;
    self->f65 = 0xFF;
    if (self->f98 != 0) {
        self->f98 = self->f24->f10;
    }
    if (self->f24 != NULL) {
        if (self->f24->f40 != 0) {
            self->f34 |= 0x10;
            self->f60 = self->f24->f40;
        } else {
            self->f60 = 0;
            self->f34 &= 0xFFEF;
        }
        if (self->f24->fF != 0) {
            self->f76 = 0x18;
            self->f34 |= 0x400;
        } else {
            self->f76 = 0;
            self->f34 &= 0xFBFF;
            self->f7C = 0;
        }
        if (self->f24->f6 != 0) {
            self->f66 = 0x18;
        } else {
            self->f66 = 0;
        }
    }
    func_L00_005E4118(self);
    return 1;
}

#include "common.h"

extern void func_L00_005DD4A0(void *);
extern s32 func_L00_005E60D0(s32, s32);
extern void func_L00_005E75B0(void *, s32, s32, f32);
extern s32 func_L00_005E8F08(void *, s32, s32);
extern s32 func_L00_0066D220(s32, s32, void *);
extern void func_L01_00591BD8(void *, s32, s32);
extern void func_L01_005A0A30(void *, s32, s32);

typedef struct {
    u8 pad0[0x3C];
    void *owner;
} Slot;

extern Slot D_0023EDC0[];

typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x2C - 0x21];
    u8 slot;
} Obj;

void func_L06_00416C20(Obj *o) {
    s32 ok;
    f32 f;

    switch (o->state) {
    case 0:
        f = func_L00_005E60D0(0, 0x13);
        func_L00_005E75B0(o, 2, func_L00_005E60D0(0, 0x13), f);
        func_L01_00591BD8(o, 1, -1);
        break;
    case 1:
        if (o->slot == 0xFF || (D_0023EDC0 + o->slot)->owner != o) {
            ok = 0;
        } else {
            ok = func_L00_005E8F08(o, 0x0FFFFFFF, 0);
        }
        if (ok) {
            func_L00_0066D220(0, 0, o);
            func_L01_005A0A30(o, 0x26CC, 0);
            func_L00_005DD4A0(o);
        }
        break;
    }
}

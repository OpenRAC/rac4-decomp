#include "common.h"

typedef struct Pvar {
    s32 x0;
    u8 pad4[0x38];
    u8 slot;
    u8 pad3D[0x3];
    s16 x40;
    u8 pad42[0x2];
    s32 x44;
    u8 *x48;
    u8 pad4C[0x1C];
    s32 x68;
    s32 x6C;
} Pvar;

extern s32 D_00171250[];
extern s32 D_00171EF8[][10];
extern s32 D_00171E80[][10];
typedef struct Stats {
    u8 pad0[0x18];
    s32 a[3][4];
    s32 b[3][4];
} Stats;
extern Stats D_00171DB8;
extern void func_L01_0068D8F8(u8 *, s32);
extern void func_L01_00457468(void);

// weapon reset
void func_L01_004561B8(u8 *moby) {
    Pvar *pv;

    pv = *(Pvar **)(moby + 0xAC);
    D_00171EF8[D_00171250[*(s32 *)(pv->x48 + 0x2F10)]][pv->slot] = 0;
    D_00171DB8.b[D_00171250[*(s32 *)(pv->x48 + 0x2F10)]][pv->slot] = 0;
    D_00171E80[D_00171250[*(s32 *)(pv->x48 + 0x2F10)]][pv->slot] = 0;
    D_00171DB8.a[D_00171250[*(s32 *)(pv->x48 + 0x2F10)]][pv->slot] = 0;
    if (pv->x0 == 0) {
        func_L01_0068D8F8(pv->x48, 2);
    } else {
        func_L01_0068D8F8(pv->x48, 3);
    }
    pv->x40 = 0;
    pv->x44 = 0;
    pv->x68 = 0;
    pv->x6C = 0;
    func_L01_00457468();
}

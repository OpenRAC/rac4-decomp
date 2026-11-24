#include "common.h"

typedef struct Menu {
    u8 pad0[0xC];
    s32 selected;
    s32 busy;
    u8 pad14[0x60];
} Menu;

typedef struct Item {
    s32 id;
    u8 pad4[0x8];
} Item;

extern u16 D_001F628C[];
extern Menu D_0030B7F8[];
extern Item D_003D21F0[];
extern s32 D_00221980;
extern void func_0045E478(s32, s32);
extern s32 func_00506BB8(void);
extern s32 func_00499120(s32);
extern s32 func_00499118(void);
extern s32 func_00498518(s32);
extern s32 func_00498F30(s32, s32);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005061B0(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_005052D0(s32, f32, f32);
extern s32 func_00506000(s32, s32);
extern u32 func_004C3D08(s32, s32);
extern s32 func_005063C0(s32, u32);
extern void func_004985F0(s32);
extern void func_004C52B8(void);
extern void func_004C4078(s32);
extern void func_004C4C70(void);
extern void func_004C3EE0(s32);
extern void func_004C52E0(void);

// Per-frame update of a list menu: sets its labels and, for each list
// event, moves the cursor and recolours the entries or calls the handler.
void func_004C5030(void)
{
    Menu *m;
    s32 s;
    s32 i;
    s32 h;
    f32 x;
    f32 y;
    f32 z;

    if (D_001F628C[0]) {
        func_0045E478(0x2FAD, 0x682);
        func_0045E478(0x2FAE, 0x683);
    } else {
        func_0045E478(0x2FA3, 0x678);
        func_0045E478(0x2FA4, 0x679);
        func_0045E478(0x2FA5, 0x67A);
        func_0045E478(0x2FA6, 0x67B);
        func_0045E478(0x2FA7, 0x67C);
    }
    m = &D_0030B7F8[func_00506BB8()];
    switch (func_00499120(6)) {
    case 1:
        if (m->busy) {
            func_004C4C70();
        } else {
            s = func_00499118();
            if (!func_00498F30(s, func_00498518(m->selected))) {
                func_004985F0(4);
            } else {
                func_005061B0(func_004A2798(&D_00221980, D_003D21F0[m->selected].id), &x, &y, &z, &z);
                func_005052D0(func_004A2798(&D_00221980, s + 0xDC), x, y);
                func_00506000(func_004A2798(&D_00221980, s + 0xDC), 1);
                for (i = 0; i < 10; i++) {
                    h = func_004A2798(&D_00221980, D_003D21F0[i].id);
                    func_005063C0(h, func_004C3D08(i, i == m->selected));
                }
                func_004985F0(0x21);
            }
        }
        break;
    case 2:
        func_004C52B8();
        break;
    case 5:
        func_004C4078(1);
        break;
    case 6:
        func_004C4078(0);
        break;
    case 7:
        if (m->busy) {
            func_004985F0(4);
        } else {
            func_004C3EE0(1);
        }
        break;
    case 8:
        if (m->busy) {
            func_004C4C70();
        } else {
            func_004C3EE0(0);
        }
        break;
    case 9:
    case 10:
        func_004C3EE0(1);
        break;
    case 11:
    case 12:
        func_004C3EE0(0);
        break;
    case 13:
        func_004C52E0();
        break;
    }
}

#include "common.h"

typedef void (*Callback)(void);

typedef struct Screen {
    s32 mode;
    s32 selected;
    s32 flags;
} Screen;

extern Screen D_0030E9D8;
s32 D_0021FAC8 = -1;
s32 D_0021FACC = 1;
s32 D_0021FAD4 = 0;
extern u8 D_0021EE98;
extern s32 D_00171BAC[];
extern s32 D_0023AC18[];
extern void func_004CBE60(void);
extern void func_004CBE80(void);
extern void func_004CBEC8(void);
extern void func_004CBF18(void);
extern void func_004CBF90(void);
extern void func_004CBFE8(void);
extern void func_004CC038(void);
extern void func_004CC0C0(void);
extern void func_004CC110(void);
extern void func_004CC138(void);
extern void func_004CC1E8(void);
extern void func_004CC218(void);
extern s32 func_004CB688(void);
extern void func_004CB608(void);
extern s32 func_004D3270(s32);
extern void func_004D31F0(s32);
extern void func_004D3158(s32, Callback, s32);
extern void func_004CB630(char *, Callback, s32, s32);
extern char *func_0045E898(s32);
extern char *func_0045E850(s32);
extern void func_00466458(s32, s32, Callback, Callback);
extern void func_00466758(s32);
extern void func_00469308(s32);
extern void func_00466940(s32);

// Moves the save screen to a new state. Most states show a message box
// (func_004CB630) with its text and callback; some start another operation first.
void func_004CB038(s32 state, s32 quiet)
{
    if (!quiet && func_004CB688()) {
        func_004CB608();
    }
    if (func_004D3270(0)) {
        func_004D31F0(0);
    }
    switch (state) {
    case 0:
        if (D_0021FAC8 == 1) {
            if (D_0021EE98) {
                func_004CB630(func_0045E898(0x19C), func_004CBFE8, 3, 1);
            } else {
                func_004CB630(func_0045E898(0x19E), func_004CBE60, 2, 0);
            }
        } else {
            func_004CB630(func_0045E898(0x196), func_004CBE60, 2, 0);
        }
        break;
    case 1:
        D_0030E9D8.flags |= 1;
        break;
    case 2:
        func_004D3158(0, func_004CC038, D_0021FACC);
        break;
    case 3:
        func_004D3158(0, func_004CC0C0, D_0021FACC);
        break;
    case 5:
        func_004CB630(func_0045E898(0x1A3), func_004CBE80, 3, 1);
        break;
    case 6:
        func_00466458(5, 0, 0, 0);
        func_004CB630(func_0045E898(0x1AD), 0, 1, 0);
        break;
    case 7:
        func_00466758(3);
        func_004CB630(func_0045E898(0x1B0), func_004CBE60, 2, 0);
        break;
    case 8:
        func_00466458(6, 0, 0, 0);
        func_004CB630(func_0045E898(0x1AF), 0, 1, 0);
        break;
    case 9:
        func_004CB630(func_0045E898(0x1A0), func_004CBEC8, 3, 1);
        break;
    case 10:
        func_00466458(4, 0, 0, 0);
        func_004CB630(func_0045E898(0x1AE), 0, 1, 0);
        break;
    case 11:
        func_00466758(3);
        func_004CB630(func_0045E898(0x1B2), func_004CBE60, 2, 0);
        break;
    case 12:
        if (D_0021EE98) {
            func_004CB630(func_0045E898(0x3785), func_004CBFE8, 3, 1);
        } else {
            func_004CB630(func_0045E898(0x199), func_004CBE60, 2, 0);
        }
        break;
    case 13:
        func_004CB630(func_0045E898(0x30F2), func_004CBF18, 3, 0);
        break;
    case 14:
        func_004CB630(func_0045E898(0x1A9), func_004CBF18, 3, 1);
        break;
    case 15:
        D_0021FAD4 = D_00171BAC[0];
        func_00466458(2, D_0030E9D8.selected, func_004CC110, func_004CC138);
        func_004CB630(func_0045E898(0x1AB), 0, 1, 0);
        break;
    case 17:
        func_00466758(3);
        if (D_0021FAD4) {
            func_004CB630(func_0045E898(0x1B3), func_004CBF18, 2, 0);
        } else {
            func_004CB630(func_0045E898(0x1B2), func_004CBF18, 2, 0);
        }
        break;
    case 18:
        func_004CB630(func_0045E898(0x1A2), func_004CBFE8, 3, 1);
        break;
    case 19:
        func_004CB630(func_0045E850(0x19A), func_004CBFE8, 3, 1);
        break;
    case 21:
        func_00466458(6, 0, 0, 0);
        func_004CB630(func_0045E898(0x1AF), 0, 1, 0);
        break;
    case 22:
        func_004CB630(func_0045E898(0x3788), func_004CBE60, 2, 0);
        break;
    case 23:
        func_004CB630(func_0045E898(0x144), func_004CBF90, 3, 1);
        break;
    case 24:
        func_00469308(D_0023AC18[0]);
        func_00466458(3, D_0030E9D8.selected, func_004CC1E8, func_004CC218);
        func_004CB630(func_0045E898(0x1AC), 0, 1, 0);
        break;
    case 26:
        func_00466940(D_0023AC18[0]);
        func_00466758(3);
        func_004CB630(func_0045E898(0x1B1), func_004CBF18, 2, 0);
        break;
    case 27:
        break;
    }
    D_0030E9D8.mode = state;
}

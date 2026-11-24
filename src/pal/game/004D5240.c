#include "common.h"

typedef struct Pad {
    u8 pad0[0x1A4];
    s32 buttons;
} Pad;

typedef struct Card {
    u8 pad0[0x8];
    s32 state;
    u8 padC[0x4];
    s32 result;
} Card;

extern Pad *D_0021DE54;
extern Card D_001719C8;
extern u8 D_0021EE98;
extern u8 D_0021EE99;
extern u8 D_002214E0;
s32 D_0021FC2C = 0;
extern s32 func_00466450(void);
extern void func_00466758(s32);
extern void func_00466458(s32, s32, s32, s32);
extern void func_00466640(s32);
extern void func_004800B0(s32, s32);
extern void func_00465338(s32);
extern void func_00466A20(void);
extern void func_004E6478(void);
extern s32 func_004666C8(s32);

// Handles the buttons while a memory-card message is shown: for each card
// state it starts the next card step, closes the message or moves on.
void func_004D5240(void)
{
    s32 b;

    switch (func_00466450()) {
    case 3:
        if (D_0021DE54->buttons & 0x40) {
            func_00466758(3);
            D_0021FC2C++;
        }
        break;
    case 8:
        b = D_0021DE54->buttons;
        if (b & 0x20) {
            func_00466458(5, 0, 0, 0);
        } else if (b & 0x10) {
            if (D_0021EE99) {
                func_004E6478();
            } else {
                func_00466758(2);
                func_00466640(1);
                func_00466640(3);
                if (!D_0021EE98) {
                    func_004800B0(6, 0);
                }
            }
        }
        break;
    case 15:
        b = D_0021DE54->buttons;
        if (b & 0x20) {
            break;
        }
        if (!(b & 0x10)) {
            break;
        }
        if (D_0021EE99) {
            func_004E6478();
        } else {
            func_00466640(0);
            func_00466758(2);
            if (!D_0021EE98) {
                D_0021FC2C++;
            }
        }
        break;
    case 22:
        if (D_0021DE54->buttons & 0x40) {
            func_00466640(0);
            func_00466758(3);
            /* Both arms are the same, but retail still loads D_0021EE98 here
               (into a delay slot). The original arms probably differed only
               in code compiled out of this build. */
            if (D_0021EE98) {
                D_0021FC2C++;
            } else {
                D_0021FC2C++;
            }
        }
        break;
    case 19:
    case 20:
    case 24:
        if (D_001719C8.state != 2) {
            func_004E6478();
        } else {
            s32 v = D_001719C8.result;

            if (v == 0) {
                func_00465338(11);
            } else if (v == -1) {
                D_001719C8.result = 0;
                func_00465338(11);
            } else if (v == -2) {
                func_00465338(7);
            } else {
                func_00465338(14);
            }
            D_0021FC2C++;
        }
        break;
    case 14:
        if (!D_002214E0) {
            break;
        }
    case 4:
    case 5:
    case 7:
        if (D_0021DE54->buttons & 0x40) {
            func_00466640(0);
            D_0021FC2C++;
        }
        break;
    case 21:
        if (D_0021EE98 && !D_002214E0) {
            if (D_0021DE54->buttons & 0x40) {
                func_00466A20();
                func_00466640(0);
                func_004E6478();
            }
        } else if (D_0021EE99) {
            if (D_0021DE54->buttons & 0x40) {
                func_004E6478();
            }
        } else if (D_0021DE54->buttons & 0x40) {
            func_00466640(0);
            D_0021FC2C++;
        }
        break;
    case 26:
    case 27:
        b = D_0021DE54->buttons;
        if (b & 0x40) {
            func_00466A20();
            func_00466758(3);
            func_004E6478();
        } else if (b & 0x10) {
            func_00466758(3);
            D_0021FC2C++;
        }
        break;
    case 6:
        if (D_0021EE98 && !D_002214E0) {
            if (D_0021DE54->buttons & 0x40) {
                func_00466A20();
                func_00466640(0);
                func_004E6478();
            }
            if (D_0021DE54->buttons & 0x10) {
                func_00466640(0);
                func_00466758(2);
                D_0021FC2C++;
            }
        } else if (D_0021EE98) {
            if (D_0021DE54->buttons & 0x40) {
                func_00466640(0);
                func_00466758(2);
                D_0021FC2C++;
            }
        } else if (D_0021EE99) {
            if (D_0021DE54->buttons & 0x20) {
                func_004E6478();
            }
        } else if (D_0021DE54->buttons & 0x40) {
            func_00466640(0);
            func_00466758(2);
            D_0021FC2C++;
        }
        break;
    case 1:
    case 11:
    case 18:
        if (!func_004666C8(1) && !func_004666C8(3)) {
            D_0021FC2C++;
        }
        break;
    case 30:
        break;
    }
}

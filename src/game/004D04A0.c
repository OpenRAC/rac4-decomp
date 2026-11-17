#include "common.h"

extern s32 func_004A1730(void *);
extern void func_004D0AC8(void);
extern void func_004D0B08(void);
extern void func_004D0B48(void);
extern void func_004D0D48(void);
extern void func_005014B0(s32 *a0);
extern s32 func_00505B20(void);
extern u8 D_0021DE39;
extern u8 D_31A960[];
extern s32 D_002209DC;

/* Updates the state of the entry for the current owner, then its flags and its sub-entry. */
void func_004D04A0(s32 arg0) {
    u8 *e;
    s32 state;

    e = D_31A960 + func_00505B20() * 0x1A4;
    state = *(s32 *)e;
    switch (state) {
    case 1:
        *(s32 *)e = 0;
        D_002209DC = -D_0021DE39;
        break;
    case 2:
        func_005014B0((s32 *)arg0);
        D_002209DC = -D_0021DE39;
        break;
    case 0:
        func_004D0D48();
        break;
    }
    if (*(s32 *)(e + 8) & 1) {
        func_004D0AC8();
    }
    if (*(s32 *)(e + 8) & 2) {
        func_004D0B08();
    }
    func_004A1730(e + 0x138);
    if (*(s32 *)(e + 8) & 4) {
        func_004D0B48();
    }
}

#include "common.h"

typedef struct { u8 pad0[0x74]; u16 f74; u8 pad1[0x34]; u8 *fAC; } Obj;
extern s32 D_0021DE10;

/* Clear the flag word and set its bits according to the linked state. */
void func_L01_004B6CC8(Obj *obj) {
    u8 *linked = obj->fAC;

    obj->f74 = 0;
    if (linked[0x60D] == 0) {
        if (linked[0x60C] != 0 || D_0021DE10 == 1 || D_0021DE10 == 0x15) {
            obj->f74 |= 0x3E0;
        } else {
            obj->f74 = 0x1F;
        }
        obj->f74 |= 0xC00;
    }
}

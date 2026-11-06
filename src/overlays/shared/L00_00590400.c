#include "common.h"

typedef struct {
    u8 pad[0x24C];
    s32 f24C;
    u8 pad250[0x470 - 0x250];
} Type1;

typedef struct {
    u8 pad[0x94];
    s32 f94;
} Type2;

extern Type1 D_0022CA80[];
extern s32 D_0021E6B4;

/* -1 when D_0021E6B4 is not 1 and the object's record in D_0022CA80 (0x470 bytes, index at +0x94) has state 4 or 0x51, else 0. */
s32 func_L00_00590400(Type2 *o) {
    if (D_0021E6B4 != 1) {
        s32 k = ((Type1 *)(o->f94 * 0x470 + (u8 *)D_0022CA80))->f24C;
        if (k == 4 || k == 0x51) {
            return -1;
        }
    }
    return 0;
}

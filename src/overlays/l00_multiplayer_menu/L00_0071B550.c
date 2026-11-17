#include "common.h"

typedef struct Type3 {
    u8 pad0[0x18];
    s32 (*f18)(void *, s32);
} Type3;

typedef struct Type2 {
    u8 pad0[0x58];
    Type3 *f58;
} Type2;

typedef struct Type1 {
    u8 pad0[0xB0];
    Type2 *fB0[0x60];
    s32 f230;
} Type1;

extern s32 func_L00_0071B9B0(void *arg0);

/* Calls method 0x18 of the object in the slot selected by field 0x230, returning 1 when it reports 1, otherwise 0. */
s32 func_L00_0071B550(Type1 *arg0, s32 arg1) {
    func_L00_0071B9B0(arg0);
    if (arg0->f230 >= 0) {
        switch (arg0->fB0[arg0->f230]->f58->f18(arg0->fB0[arg0->f230], arg1)) {
        case 1:
            return 1;
        }
    }
    return 0;
}

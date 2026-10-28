#include "common.h"

typedef struct Type2 Type2;
struct Type2 {
    u8 pad0[0x88];
    s32 f88;
};

typedef struct {
    u8 pad0[0xAC];
    Type2 *fAC;
} Type1;

/* Read the 32-bit field at +0x88 of the object referenced at +0xAC. */
s32 func_00431758(Type1 *p) {
    return p->fAC->f88;
}

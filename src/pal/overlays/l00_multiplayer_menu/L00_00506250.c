/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
typedef struct Type3 Type3;
typedef struct Type4 Type4;

struct Type2 {
    u8 pad[0x54];
    Type3 *f54;
};

struct Type3 {
    u8 pad[0x50];
    s32 (*f50)(s32);
};

struct Type4 {
    u8 pad[0xA4];
    void *fA4;
    u8 padA8[0x64];
    s32 f10C;
    s8 f110;
    s8 f111;
};

struct Type1 {
    u8 pad[0x8];
    Type2 *f8;
    u8 padC[0x48];
    Type4 *f54;
    u8 pad58[0x58];
    void *fB0;
    u8 padB4[0x28];
    void *fDC;
};

extern s32 func_L00_00507D18(void *, void *);
extern s32 func_L00_00506300(Type1 *);

// Translates a request through a callback and records and dispatches valid results.
s32 func_L00_00506250(Type1 *arg0, s32 arg1, s32 arg2)
{
    s32 result = arg0->f8->f54->f50(arg2);

    if (result < 0) {
        return 1;
    }

    if (arg1 == 2 && arg0->fB0 != NULL) {
        func_L00_00507D18(arg0->fDC, arg0->fB0);
    }

    arg0->f54->f10C = 1;
    arg0->f54->f110 = arg1;
    arg0->f54->f111 = result;

    if (arg0->f54->fA4 == NULL) {
        return func_L00_00506300(arg0);
    }
    return -1;
}

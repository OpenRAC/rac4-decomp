/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

typedef struct Sub54 {
    u8 pad0[0x18];
    s32 f18;
    u8 pad1C[0x100 - 0x1C];
    s32 f100;
} Sub54;

typedef struct Peer {
    u8 pad0[0x54];
    Sub54 *f54;
} Peer;

typedef struct Conn {
    u8 pad0[0x4];
    void *f4;
} Conn;

typedef struct Self {
    u8 pad0[0x8];
    Peer *f8;
    u8 padC[0x3C - 0xC];
    Conn *f3C;
    u8 pad40[0x54 - 0x40];
    Sub54 *f54;
} Self;

extern s32 func_0011A2DC(void *, void *, s32);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void func_L00_00505D50(Self *, s32, s32);
extern s64 func_L00_00527340(Self *, s32, s32, s32, u64, s32 *);

s32 func_L00_00526DA8(Self *self, s32 arg1, s32 arg2) {
    s32 status;
    s64 r;
    s32 code;
    s32 len;
    void *data;

    r = func_L00_00527340(self, arg1, arg2, 0x14, 0x40, &status);
    if (status == 0) {
        return r;
    }
    if (self->f54->f100 == 0) {
        code = 10;
        func_L00_004F84C8(0x14, 0x8C, 0x9A, 0, 0);
    } else {
        self->f54->f100 = 0;
        len = self->f8->f54->f18;
        data = self->f3C->f4;
        if (len != r) {
            code = 0x32;
            func_L00_004F84C8(0x14, 0x8C, 0x6F, 0, 0);
        } else {
            if (func_0011A2DC(data, (u8 *)self->f54 + 0x128, len) == 0) {
                return 1;
            }
            code = 0x33;
            func_L00_004F84C8(0x14, 0x8C, 0x95, 0, 0);
        }
    }
    func_L00_00505D50(self, 2, code);
    return -1;
}

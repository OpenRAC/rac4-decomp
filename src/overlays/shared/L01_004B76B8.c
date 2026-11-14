#include "common.h"

extern s32 func_L00_005FE300(void *, s32);
extern void func_L01_004B6CC8(void *);
extern void func_L01_005B0B70();
extern s32 func_L01_005B4FE8(void *arg0, s32 arg1, s32 arg2);

typedef struct {
    u8 pad0[0x50];
    s32 f50;
    u8 pad54[0x211 - 0x54];
    u8 f211;
    u8 pad212[0x2F8 - 0x212];
    s32 f2F8;
    u8 pad2FC[0x60C - 0x2FC];
    u8 f60C;
    u8 f60D;
} Type2;

typedef struct {
    u8 pad0[0x9C];
    s32 f9C;
    u8 padA0[0xAC - 0xA0];
    Type2 *fAC;
} Type1;

// Reset object state flags and start its action.
void func_L01_004B76B8(Type1 *arg0) {
    Type2 *s = arg0->fAC;

    arg0->f9C = 0x400;
    s->f60D = 0;
    s->f211 = 1;
    s->f2F8 &= ~0x400;
    func_L00_005FE300(arg0, 1);
    func_L01_004B6CC8(arg0);
    if (s->f60C != 1) {
        s->f50 |= 0x40;
    }
    func_L01_005B0B70(arg0, 0x24, 9, 1, 5, 0xFFFF, 0xFFFF, -1, -1);
    func_L01_005B4FE8(arg0, 1, 1);
}

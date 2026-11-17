#include "common.h"

typedef struct {
    char _p0[0x44];
    s32 (*f44)(void *);
} Vt;

typedef struct {
    char _p0[0x58];
    Vt *f58;
} Elem;

typedef struct {
    char _p0[0xAC];
    s32 fAC;
    Elem *fB0[0x60];
    s32 f230;
    char _p234[0x265 - 0x234];
    u8 f265;
    u8 f266;
    u8 f267;
    char _p268[0x26C - 0x268];
    s32 f26C;
    char _p270[0x274 - 0x270];
    s16 f274;
    char _p276[0x284 - 0x276];
    u8 buf[0xC8];
    s32 f34C;
} Obj;

extern void func_0011A518(void *, s32, s32);
extern void func_L00_007410B8(Obj *);
extern s32 func_L00_0071B8E8(Obj *, s32, s32);
extern void func_L00_0071BA48(Obj *, u32);

void func_L00_00741990(Obj *arg0) {
    s32 idx;
    Elem *e;

    arg0->f265 = 0;
    arg0->f267 = 0;
    arg0->f274 = 0;
    arg0->f266 = 1;
    arg0->f26C = 1;
    func_L00_007410B8(arg0);
    func_L00_0071B8E8(arg0, -1, 0);
    idx = arg0->f230;
    if (idx != -1) {
        e = arg0->fB0[idx];
        func_L00_0071BA48(arg0, e->f58->f44(e));
    } else {
        func_L00_0071BA48(arg0, -1);
    }
    func_0011A518(arg0->buf, 0, 0xC8);
    arg0->f34C = 0;
}

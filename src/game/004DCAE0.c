#include "common.h"

extern f32 func_00453B10(f32, f32);
extern void func_0046E728(void *);
extern void func_0046EDD8(u8 *arg0);
extern void func_004706F0(void *object);
extern s32 func_00505B20(void);

typedef struct {
    u8 pad0[0x160];
    f32 f160;
    u8 pad164[4];
} Type1;

typedef struct {
    u8 pad0[8];
    u8 *f8;
    u8 padC[0x18];
} Type2;

extern Type1 D_322FC8[];
extern Type2 D_323130[];

// For each of the six records of D_323130 with a non-null object, scales its +0xF8 float by the current D_322FC8 entry's +0x160 float and runs three per-object calls.
void func_004DCAE0(void) {
    Type1 *cur;
    u8 *obj;
    s32 i;

    cur = &D_322FC8[func_00505B20()];
    for (i = 0; i < 6; i++) {
        obj = D_323130[i].f8;
        if (obj != 0) {
            *(f32 *)(obj + 0xF8) = func_00453B10(*(f32 *)(obj + 0xF8), cur->f160);
            func_0046E728(obj);
            func_0046EDD8(obj);
            func_004706F0(obj);
        }
    }
}

#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct Type3 {
    char _p0[0x10];
    s128 v10;
    char _p20[0x100 - 0x20];
} Type3;

typedef struct Type2 {
    char _p0[0x6C];
    s32 f6C;
    s32 f70;
} Type2;

typedef struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
} Type1;

extern s32 func_L00_005F1208(s128, s32);
extern Type3 *D_00222794;
extern u8 *D_362C78[];

/* Looks up the object's entry in the 10-slot table at D_362C78 (or the indexed table) and tests it. */
s32 func_L02_00493FB8(Type1 *arg0) {
    Type2 *p;
    u8 **slot;
    u8 *cur;
    s32 i;
    s32 idx;

    p = arg0->fAC;
    idx = p->f70;
    if (idx != -1) {
        return func_L00_005F1208(D_00222794[idx].v10, p->f6C) != 0;
    }
    i = 0;
    slot = &D_362C78[0];
    cur = D_362C78[0];
    do {
        if (cur != 0) {
            if (func_L00_005F1208(*(s128 *)(cur + 0xA0), p->f6C) != 0) {
                return 1;
            }
        }
        slot++;
        i++;
        cur = *slot;
    } while (i < 0xA);
    return 0;
}

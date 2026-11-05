/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type2 {
    char _p0[0xC];
    s32 fC;
    s32 f10;
    s32 f14;
} Type2;

typedef struct Type1 {
    s32 f0;
    char _p4[0x8];
    Type2 *fC;
} Type1;

void func_L00_004F84C8(int, int, int, int, int);
s32 func_L00_0051CE60(Type1 *);
void func_L00_00538038(s32);
s32 func_L00_00538390(s32);

s64 func_L00_0051CD28(Type1 *arg0, Type1 *arg1) {
    s32 p;

    if (arg0->f0 != arg1->f0) {
        func_L00_004F84C8(6, 0x68, 0x66, 0, 0);
        return 0;
    }
    if (func_L00_0051CE60(arg1) != 0) {
        func_L00_004F84C8(6, 0x68, 0x73, 0, 0);
        return 0;
    }
    if (arg0->f0 == 0x74) {
        p = func_L00_00538390(arg1->fC->fC);
        if (p == 0) {
            return 0;
        }
        if (arg0->fC->fC != 0) {
            func_L00_00538038(arg0->fC->fC);
        }
        arg0->fC->fC = p;
        p = func_L00_00538390(arg1->fC->f10);
        if (p == 0) {
            return 0;
        }
        if (arg0->fC->f10 != 0) {
            func_L00_00538038(arg0->fC->f10);
        }
        arg0->fC->f10 = p;
        p = func_L00_00538390(arg1->fC->f14);
        if (p == 0) {
            return 0;
        }
        if (arg0->fC->f14 != 0) {
            func_L00_00538038(arg0->fC->f14);
        }
        arg0->fC->f14 = p;
    }
    return 1;
}

#include "common.h"

typedef struct T2 { char _p0[0x615]; u8 f615; char _p616[2]; u8 f618; } T2;
typedef struct T1 { char _p0[0xAC]; T2 *fAC; } T1;

extern s64 func_L01_0045C0A0(void *);

s32 func_L01_0045D538(T1 *arg0, s32 arg1) {
    T2 *p = arg0->fAC;
    s64 r = func_L01_0045C0A0(arg0);

    switch (arg1) {
    case 1:
    case 2:
    case 3:
        return 1;
    case 4: {
        s32 t = 0;
        if (r != 0 || p->f615 != 0) t = 1;
        return t;
    }
    case 5: {
        s32 t = 0;
        if (r != 0 || p->f618 == 1) t = 1;
        return t;
    }
    case 6: {
        s32 t = 0;
        if (r != 0 || p->f618 == 2) t = 1;
        return t;
    }
    }
    return 0;
}

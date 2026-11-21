/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA8BD0(s64 arg0, s64 arg1);
extern s32 func_01EBE248(void *arg0, void *arg1, void **arg2);
extern s32 func_01EBF0A0(void *arg0, void *arg1);

typedef struct __attribute__((packed)) {
    s64 v;
} Type2;

typedef struct {
    s32 f0;
    s32 f4;
    Type2 f8;
    s32 f10;
    char _p[0x5C - 0x14];
    u16 f5C;
    u16 f5E;
    char _q[0x70 - 0x60];
    s32 f70;
    char _r[0x7C - 0x74];
    s32 f7C;
    s32 f80;
    char _s[0x88 - 0x84];
    s32 f88;
    char _t[0x90 - 0x8C];
} Ent;

typedef struct {
    char _a[8];
    Ent *f8;
    char _b[0x60 - 0xC];
    u32 f60;
} Tab;

typedef struct {
    Type2 f0;
    s32 f8;
    s32 fC;
    u16 f10;
    char _p[0x1C - 0x12];
    s32 f1C;
    s32 f20;
    s32 f24;
} Req;

/* Finds the entry in arg0's table that matches arg1, fills it in and hands it to func_01EBF0A0; otherwise falls back to func_01EBE248. */
s32 func_01EBF148(Tab *arg0, Req *arg1, Ent **arg2) {
    s32 v;
    u32 i;
    Ent *e;

    *arg2 = 0;
    if (arg0 == 0) {
        return 0xD2F2;
    }
    i = 0;
    e = arg0->f8;
    if (arg0->f60 != 0) {
        do {
            if (e->f0 == 8) {
                if (func_01EA8BD0(e->f8.v, arg1->f0.v) != 0) {
                    if (e->f10 == arg1->f8) {
                        if (e->f5C == arg1->f10) {
                            s32 a2 = arg1->fC;
                            s32 b = arg1->f1C;
                            s32 c = arg1->f20;
                            s32 a3 = arg1->f24;
                            *arg2 = e;
                            e->f70 = a2;
                            e->f80 = b;
                            e->f7C = c;
                            e->f88 = a3;
                            return func_01EBF0A0(arg0, e);
                        }
                    }
                }
            }
            i++;
            e++;
        } while (i < arg0->f60);
    }
    v = func_01EBE248(arg0, arg1, arg2);
    if (v == 0) {
        (*arg2)->f5E = 0;
    }
    return v;
}

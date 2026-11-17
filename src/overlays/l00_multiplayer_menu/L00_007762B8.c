#include "common.h"

extern s32 D_00221858;
extern void func_L00_00775680(u8 *arg0, u8 *arg1);
extern void *func_L00_007756B0(void *arg0, u32 arg1);

typedef struct Type1 {
    s32 f0;
    s32 f4;
    void *f8;
    u32 fC;
} Type1;

typedef struct Type2 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
} Type2;

/* For arg2 == 0, walks the entry list at arg3->f8 and marks each entry, then records a status in arg3. */
void func_L00_007762B8(s32 a0, s32 a1, s32 arg2, Type1 *arg3) {
    Type2 *h;
    Type2 *e;
    u32 s1;
    u32 s4;
    s32 s3;
    s32 t;

    if (arg2 == 0) {
        h = (Type2 *)arg3->f8;
        if (h->f0 == D_00221858) {
            s1 = h->f8;
            s4 = 0;
            h->fC = s1;
            if (s4 < s1) {
                s3 = s1 - 1;
                do {
                    e = (Type2 *)func_L00_007756B0(arg3->f8, s3);
                    e->f20 = s1;
                    t = e->f0 & 0x921;
                    e->f18 = 0;
                    e->f0 = t;
                    if (t == 0) {
                        func_L00_00775680((u8 *)arg3->f8, (u8 *)e);
                        e->f0 = 0;
                    } else {
                        e->f14 = 0xED000;
                    }
                    s4 += 1;
                    s3 -= 1;
                } while (s4 < s1);
            }
            arg3->f4 = 4;
        } else {
            arg3->f4 = 1;
        }
    } else {
        arg3->f4 = 3;
    }
    arg3->fC = 0xFFFFFFFFU;
}

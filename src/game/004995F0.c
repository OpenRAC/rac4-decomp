#include "common.h"

typedef struct Type2 {
    u8 pad0[4];
    s32 f4;
    u8 pad8[4];
    u8 fC;
} Type2;

typedef struct Type3 Type3;

typedef struct Type4 {
    u8 pad0[0x18];
    s32 (*f18)(Type3 *);
} Type4;

struct Type3 {
    u8 pad0[4];
    Type4 *f4;
};

typedef struct Type5 {
    u8 pad0[4];
    s32 f4;
} Type5;

typedef struct Type1 {
    Type2 *f0;
    Type3 *f4;
    s32 f8;
    s32 fC;
    Type5 *f10;
} Type1;

extern void func_00453718(void *, const void *, u32);
extern Type2 *func_00499320(s32, s32);
extern void func_004993D0(Type2 *arg0);
extern s32 func_004A2D90(Type3 *arg0, s32 arg1, s32 arg2);
extern Type1 D_002F3950[];

/* Move each active entry's buffer into a newly allocated one and rebind it. */
void func_004995F0(void) {
    s32 i;
    Type1 *e;
    Type2 *old;
    Type2 *buf;

    for (i = 0; i < 32; i++) {
        e = &D_002F3950[i];
        old = e->f0;
        if (e->f8 != 0 && old->fC != 0) {
            buf = func_00499320(e->f10->f4 << 11, 0);
            if (buf != 0) {
                func_00453718((void *)buf->f4, (void *)old->f4, e->f10->f4 << 11);
                e->f0 = buf;
                if (e->f4->f4->f18(e->f4) != 0) {
                    func_004A2D90(e->f4, buf->f4, 0);
                }
            } else {
                func_004A2D90(e->f4, 0, 0);
            }
            func_004993D0(old);
        }
    }
}

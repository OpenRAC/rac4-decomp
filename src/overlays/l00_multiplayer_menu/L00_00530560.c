/* cflags: @ee29 -O2 -G8 */
#include "common.h"

typedef struct {
    void *p;
    s32 eos;
    s32 error;
    s32 inf;
    s32 tag;
    s32 xclass;
    s64 slen;
    void *max;
    void *q;
    void **pp;
    s32 line;
} Type1;

typedef struct {
    s32 unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} T;

extern s64 func_L00_004F84C8();
extern void *func_L00_004FACD8(s32);
extern void *func_L00_0052F190(void);
extern void *func_L00_00536290(s32 arg0);
extern s32 func_L00_005423D8(void);

void *func_L00_00530560(void) {
    T *p;
    void *r;

    Type1 c;

    p = func_L00_004FACD8(0x1C);
    if (p == 0) {
        c.line = 0x52;
        func_L00_004F84C8(0xD, 0xD5, 0x21, 0, 0);
        return 0;
    }
    p->unk0 = 0;
    p->unk10 = 0;
    p->unk18 = 0;
    p->unk14 = 1;
    p->unk4 = func_L00_0052F190();
    if (p->unk4 == 0) return 0;
    p->unk8 = func_L00_005423D8();
    if (p->unk8 == 0) return 0;
    r = func_L00_00536290(3);
    p->unkC = r;
    return r == 0 ? 0 : p;
}

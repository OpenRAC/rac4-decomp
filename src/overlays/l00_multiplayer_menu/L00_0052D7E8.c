/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14[2];
    s32 f1C;
    s32 f20;
} Type1;
void *func_L00_004FACD8(s32);
s32 func_L00_004F8888(void *, void *);
s32 func_L00_00508028(s32);
void *func_0011A518(void *, s32, s32);
void func_L00_0051AD48(s32, void *, void *);
extern s32 D_004A1AFC;
extern void func_L00_0052D760(void);
extern void func_L00_0052D7A0(void);
Type1 *func_L00_0052D7E8(void) {
    s32 a;
    s32 b;
    s32 *s0;
    Type1 *p;
    p = func_L00_004FACD8(0x24);
    if (p == 0) return 0;
    a = func_L00_004F8888((void *)func_L00_0052D760, (void *)func_L00_0052D7A0);
    p->f0 = 1;
    p->f4 = a;
    s0 = p->f14;
    b = func_L00_00508028(0);
    p->fC = 0;
    p->f10 = 0;
    p->f8 = b;
    func_0011A518(s0, 0, 8);
    p->f1C = 1;
    func_L00_0051AD48(D_004A1AFC, p, s0);
    return p;
}

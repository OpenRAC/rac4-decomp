/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

typedef struct {
    char _p0[0x10];
    s32 f10;
    char _p14[0x18];
    s32 f2C;
    s32 f30;
    char _p34[0x4];
    char f38[0x7C];
    s32 fB4;
    s32 fB8;
    s32 fBC[0x20];
    s32 f13C;
    char _p140[0x4];
    s32 f144;
    s32 f148;
    s32 f14C;
    s32 f150;
} Type1;
extern void func_01EEDCD0(char *, char *, s32);
extern void func_0011A518(void *, s32, s32);
extern void *memcpy(void *, const void *, unsigned int);
extern char D_0019DA80[];
extern s32 D_0019DA90[];
void func_01EFFA10(Type1 *arg0) {
    func_01EEDCD0(arg0->f38, D_0019DA80, 0x40);
    func_0011A518(arg0->fBC, 0, 0x80);
    memcpy(arg0->fBC, D_0019DA90, 7);
    arg0->fB4 = 0xE;
    arg0->fB8 = 1;
    arg0->f13C = 0;
    arg0->f30 = 0xFF000000;
    arg0->f2C = -1;
    arg0->f14C = 0xFF000000;
    arg0->f144 = -1;
    arg0->f148 = -0x100;
    arg0->f150 = 0xFF000000;
    arg0->f10 = 1;
}

#include "common.h"

typedef struct Type2 {
    char _p0[0x194];
    s32 f194;
    char _p198[0x19C - 0x198];
    s32 f19C;
    char _p1A0[0x2A0 - 0x1A0];
    u32 f2A0;
    char _p2A4[0x2C0 - 0x2A4];
    void *f2C0;
    char _p2C4[0x2C8 - 0x2C4];
    f32 f2C8;
} Type2;

typedef struct Type1 {
    char _p0[0x20];
    u8 f20;
    char _p21[0xAC - 0x21];
    Type2 *fAC;
    char _pB0[0xBC - 0xB0];
    s16 fBC;
    char _pBE[0xF8 - 0xBE];
    f32 fF8;
} Type1;

extern void func_00591C70(Type1 *object, s32 arg1);
extern u8 *func_L00_005DD000(s32, s32);
extern void func_L00_005E7538(void *, s32, f32);
extern void func_L00_005F1180(void *, void *);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L01_005A8A28(u8 *obj);

/* Resets the object's state block and allocates its buffer on first use. */
void func_L01_00486F70(Type1 *arg0) {
    Type2 *p = arg0->fAC;
    u8 *buf;

    p->f2C8 = arg0->fF8;
    func_L00_005E7538(arg0, 0, 0.0f);
    func_L01_005A8A28(arg0);
    p->f19C = 3;
    p->f194 = 0;
    if (p->f2C0 == 0) {
        buf = func_L00_005DD000(0x2007, 0x80);
        p->f2C0 = buf;
        if (buf != 0) {
            func_L00_005F1180(buf, arg0);
        }
    }
    p->f2A0 = 0xFFFFFFFF;
    func_L01_00591BD8(arg0, 1, -1);
    func_00591C70(arg0, 0);
}

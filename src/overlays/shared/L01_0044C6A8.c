#include "common.h"

extern f32 func_004725D8(f32, f32);
extern void func_00473A88(void *, s32, s32);
extern void func_00510E28(void *, u8 **);
extern void func_L01_0044BC50(void *);

void func_L01_0044C6A8(void *obj) {
    u8 *q;
    s32 *p = *(s32 **)((u8 *)obj + 0xAC);
    f32 *f;
    s32 i;
    *((u8 *)obj + 0x30) = 0xFF;
    q = 0;
    func_00510E28(obj, &q);
    p[0] = -1;
    if (q != 0) {
        p[0] = *(s32 *)(q + 0x2F10);
    }
    func_L01_0044BC50(obj);
    *((u8 *)obj + 0xBE) &= 0xFB;
    *(s16 *)((u8 *)p + 8) = -1;
    *((u8 *)p + 0x12) = 0;
    *((u8 *)p + 0x13) = 0;
    *(s16 *)((u8 *)p + 0x10) = 0;
    p[1] = 0;
    if (q != 0) {
        *(u16 *)((u8 *)obj + 0x74) |= 2;
    } else if (p[3] != 0) {
        *(u16 *)((u8 *)obj + 0x74) |= 1;
    }
    f = (f32 *)(p + 9);
    i = 3;
    do {
        i--;
        *f = func_004725D8(0.01f, 0.03f);
        f++;
    } while (i >= 0);
    func_00473A88(obj, 1, -1);
}

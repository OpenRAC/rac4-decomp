/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern char D_0019CAD0[];
extern void func_01F0C090(const char *, s32);

// Calls the vtable method at +0x44 of the object at +0x80, with fields of arg0 as arguments.
void func_01EF62AC(u8 *arg0) {
    void **s1;
    u8 *vt;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 t0;
    s32 t1;
    s32 t3;
    f32 f12;
    f32 f13;
    f32 f14;
    f32 f15;
    f32 f16;

    s1 = *(void ***)(*(u8 **)(arg0 + 0x80));
    if (s1 == NULL) {
        func_01F0C090(D_0019CAD0, 0x63);
    }
    if (*(s32 *)arg0 == 0) {
        func_01F0C090(D_0019CAD0, 0x64);
    }
    vt = *(u8 **)s1;
    a1 = *(s32 *)(arg0 + 4);
    f12 = *(f32 *)(arg0 + 0x18);
    f13 = *(f32 *)(arg0 + 0x1C);
    f14 = *(f32 *)(arg0 + 0x24);
    f15 = *(f32 *)(arg0 + 0x28);
    a2 = *(s32 *)(arg0 + 0x2C);
    a3 = *(s32 *)(arg0 + 0x30);
    t0 = *(s32 *)(arg0 + 0xB8);
    t1 = *(s32 *)(arg0 + 0xBC);
    f16 = *(f32 *)(arg0 + 0xB4);
    t3 = *(s32 *)(arg0 + 0xA0);
    if (*(s32 *)(arg0 + 0xC0) != 0 || *(s32 *)(arg0 + 0xC4) != 0 || *(s32 *)(arg0 + 0xC8) != 0 || *(s32 *)(arg0 + 0xCC) != 0) {
        (*(void (**)(void **, s32, s32, s32, s32, s32, void *, s32, f32, f32, f32, f32, f32))(vt + 0x44))(s1, a1, a2, a3, t0, t1, arg0 + 0xC0, t3, f12, f13, f14, f15, f16);
    } else {
        (*(void (**)(void **, s32, s32, s32, s32, s32, void *, s32, f32, f32, f32, f32, f32))(vt + 0x44))(s1, a1, a2, a3, t0, t1, NULL, t3, f12, f13, f14, f15, f16);
    }
}

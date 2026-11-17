#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_0015CB10(s32 a, s32 b);
extern s32 func_L00_0077D0F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_L00_0077D148(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

// Lays out three 4-byte-aligned sections in the buffer at arg1 on first use, then calls func_0015CB10.
void func_L00_00770E78(u8 *object, u32 base, s32 unused, s32 n) {
    u32 p;
    u32 q;
    u32 m;
    u32 al;
    s32 size;
    s32 end;
    u8 *a;
    u8 *b;
    if (object[0] == 0) {
        object[8] = 0;
        *(s32 *)(object + 0x2C) = n;
        object[0] = 1;
        p = base;
        size = func_L00_0077D148(p, n * 2, 0x48, 4);
        *(s32 *)(object + 0x48) = func_L00_0077D0F0(p, size, 0x48, 4);
        p += size;
        al = 4;
        m = p % al;
        q = p;
        if (m != 0) {
            q = p + (al - m);
        }
        p = q;
        *(u32 *)(object + 0x18) = p;
        p = p + n * 4;
        m = p % al;
        q = p;
        if (m != 0) {
            q = p + (al - m);
        }
        p = q;
        *(u32 *)(object + 0x4C) = p;
        func_0011A518((void *)p, 0, *(s32 *)(object + 0x2C) * 8);
        a = object + 0x30;
        *(s32 *)(object + 0x30) = 0;
        *(s32 *)(a + 8) = *(s32 *)(object + 0x4C);
        *(s32 *)(a + 4) = 0;
        b = object + 0x3C;
        *(s32 *)(object + 0x3C) = 0;
        end = *(s32 *)(object + 0x2C) * 4 + *(s32 *)(object + 0x4C);
        *(s32 *)(b + 4) = 0;
        *(s32 *)(b + 8) = end;
    }
    func_0015CB10((s32)(object + 0x14), *(s32 *)(object + 0x18));
}

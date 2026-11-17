#include "common.h"

extern void func_L00_005DD4A0(void *);
extern s32 func_L00_0066D220(s32, s32, void *);
extern void func_L01_0055B010();

// Set up the object's state by its mode, then notify or forward to the helper.
void func_L01_00428770(u8 *object) {
    u8 *st = *(u8 **)(object + 0xAC);

    if (st[0x30] != 0 && *(s16 *)(st + 0x28) == 1) {
        u8 *b = *(u8 **)(object + 0xB8);
        b[0x23] = 0x80;
        *(u16 *)(b + 0x34) = (*(u16 *)(b + 0x34) | 1) & 0xFFFD;
        func_L00_0066D220(1, 0, object);
        func_L00_005DD4A0(object);
    } else if (*(s16 *)(st + 0x28) == 2) {
        u8 *c = *(u8 **)(object + 0xB8);
        *(u16 *)(c + 0x34) = (*(u16 *)(c + 0x34) & 0xFFBC) | 0x1000;
        *(s32 *)(c + 0x98) = *(s32 *)(*(u8 **)(c + 0x24) + 0x10);
        func_L00_0066D220(0, 0, object);
        func_L00_005DD4A0(object);
    } else {
        func_L01_0055B010(*(u8 **)(object + 0xB8), st + 0x2A, st + 0x28, st, st + 0x10,
                          st[0x2E], st[0x2F], *(s16 *)(st + 0x2C), *(s32 *)(st + 0x20), *(s32 *)(st + 0x24));
    }
}

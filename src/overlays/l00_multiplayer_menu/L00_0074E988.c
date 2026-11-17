#include "common.h"

extern s32 func_L00_005C9F50(s32);
extern u8 *D_002233A4;

/* Configures two child widgets and sets a timer on the shared state. */
void func_L00_0074E988(u8 *self) {
    s32 v;
    u8 *c;
    u8 *g;

    v = func_L00_005C9F50(0x1009);
    c = *(u8 **)(self + 0xD0);
    (*(void (**)(void *, s32, s32 *))(*(u8 **)(c + 0x58) + 0x80))(c, 1, &v);
    c = *(u8 **)(self + 0xD0);
    (*(void (**)(void *, s32, s32))(*(u8 **)(c + 0x58) + 0x20))(c, 3, 0);
    c = *(u8 **)(self + 0xCC);
    (*(void (**)(void *))(*(u8 **)(c + 0x58) + 0x7C))(c);
    g = *(u8 **)(D_002233A4 + 0x60);
    g[0x168] = 1;
    *(s32 *)(g + 0x16C) = 10000;
    self[0x260] = 1;
    c = *(u8 **)(self + 0xD0);
    (*(void (**)(void *, s32))(*(u8 **)(c + 0x58) + 0xA0))(c, 1);
    c = *(u8 **)(self + 0xCC);
    (*(void (**)(void *, s32))(*(u8 **)(c + 0x58) + 0xA0))(c, 1);
}

#include "common.h"

extern u8 *D_002233A4;
extern s32 func_L00_005C9F50(s32);

/* Sets up widgets through their vtables. */
void func_L00_00728E70(void *arg0) {
    s32 sp;

    {
        u8 *a = *(u8 **)((u8 *)arg0 + 0xB8);
        (*(void (**)(void *, s32))(*(u8 **)(a + 0x58) + 0xE8))(a, *(s32 *)(D_002233A4 + 0x3C) + 4);
    }
    sp = func_L00_005C9F50(0x1009);
    {
        u8 *b = *(u8 **)((u8 *)arg0 + 0xD0);
        (*(void (**)(void *, s32, s32 *))(*(u8 **)(b + 0x58) + 0x80))(b, 1, &sp);
    }
    {
        u8 *b = *(u8 **)((u8 *)arg0 + 0xD0);
        (*(void (**)(void *, s32, s32))(*(u8 **)(b + 0x58) + 0x20))(b, 3, 0);
    }
    {
        u8 *c = *(u8 **)((u8 *)arg0 + 0xCC);
        (*(void (**)(void *))(*(u8 **)(c + 0x58) + 0x7C))(c);
    }
    {
        u8 *o = *(u8 **)(D_002233A4 + 0x60);
        *(u8 *)(o + 0x168) = 1;
        *(s32 *)(o + 0x16C) = 0x2710;
    }
    *(u8 *)((u8 *)arg0 + 0x260) = 1;
    {
        u8 *b = *(u8 **)((u8 *)arg0 + 0xD0);
        (*(void (**)(void *, s32))(*(u8 **)(b + 0x58) + 0xA0))(b, 1);
    }
    {
        u8 *c = *(u8 **)((u8 *)arg0 + 0xCC);
        (*(void (**)(void *, s32))(*(u8 **)(c + 0x58) + 0xA0))(c, 1);
    }
}

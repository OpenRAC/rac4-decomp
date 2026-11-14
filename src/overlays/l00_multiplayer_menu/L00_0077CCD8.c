#include "common.h"

extern u16 D_00221928[];
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED8450(u8 *obj, s32 arg1, s32 arg2);
extern void func_0015D7C8(void);

// Builds a small record from the stored halfword and reports whether the follow-up call returned zero.
s32 func_L00_0077CCD8(s32 arg0, s32 arg1) {
    u8 buf[32];

    *(u16 *)buf = D_00221928[0];
    *(s32 *)(buf + 0x18) = arg1;
    func_0015B548(func_01ED8450(buf, (s32)func_0015D7C8, 0));
    return func_0015B558() == 0;
}

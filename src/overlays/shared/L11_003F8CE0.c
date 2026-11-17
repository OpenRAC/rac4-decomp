/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 func_L01_00513E78();
extern s32 func_L01_00588B08(void *object);
s32 D_00220E50 = 0;
s32 D_00220E54 = 0;
s32 D_00220E58 = 0;
char D_00220E60[8] = {0};
char D_00220E68[8] = {0};
char D_00220E70[8] = {0};

/* Initialise the object's state once, then update it. */
void func_L11_003F8CE0(void *object) {
    u8 *o = (u8 *)object;
    u8 *s = *(u8 **)(o + 0xAC);
    s32 v;
    if (o[0x20] == 0) {
        o[0x20] = 1;
        *(char **)(s + 0x14) = D_00220E60;
        *(char **)(s + 0x10) = D_00220E68;
        *(s32 *)(s + 0xC) = 0;
        *(s32 *)(s + 4) = D_00220E50;
        *(s32 *)(s + 0x18) = D_00220E54;
        v = D_00220E58;
        *(char **)(s + 8) = D_00220E70;
        *(s32 *)(s + 0x1C) = v;
        *(s32 *)s = 0;
        *(s32 *)(s + 0x20) = D_00220E54;
        func_L01_00588B08(object);
    }
    func_L01_00513E78(object);
}

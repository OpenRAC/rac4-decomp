#include "common.h"
extern u8 *func_0046D428(s32, s32, s32);
typedef s32 (*Fn)(u8 *);
void func_L01_0056E630(u8 *o, s32 m) {
    u8 *t;
    s32 on;
    u8 fl, r;
    if (o != 0) {
        t = func_0046D428(*(s16 *)(o + 0xBC), 0x13, 0xC);
        on = 0;
        if (t != 0) {
            if (m == 0 || (m == -1 && ((Fn)*(u32 *)(t + 8))(o) != 0)) {
                ((Fn)*(u32 *)(t + 0))(o);
            } else {
                ((Fn)*(u32 *)(t + 4))(o);
            }
            return;
        }
        fl = o[0xBE];
        if (m == 1 || (m == -1 && !(fl & 4))) on = 1;
        r = fl | 4; if (on == 0) r = fl & 0xFB;
        o[0xBE] = r;
    }
}

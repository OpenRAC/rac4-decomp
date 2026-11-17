#include "common.h"

extern void func_00591C70(void *object, s32 arg1);
extern u8 *func_L00_005DD000(s32, s32);
extern void func_L00_005E7538(void *, s32, f32);
extern void func_L00_005F1180(void *, void *);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L01_005A8A28(u8 *obj);

/* Resets the object's float timers, sets its state to 3, and allocates its 0x80-byte buffer on first use. */
void func_L01_004BBAE0(u8 *obj) {
    u8 *s0;
    u8 *p;
    f32 t;

    s0 = *(u8 **)(obj + 0xAC);
    t = *(f32 *)(obj + 0xF8);
    *(s32 *)(s0 + 0x2BC) = 0;
    *(f32 *)(s0 + 0x2A4) = t;
    func_L00_005E7538(obj, 0, *(f32 *)(s0 + 0x2BC));
    func_L01_005A8A28(obj);
    *(s32 *)(s0 + 0x19C) = 3;
    *(s32 *)(s0 + 0x194) = 0;
    if (*(u8 **)(s0 + 0x2C0) == 0) {
        p = func_L00_005DD000(0x2007, 0x80);
        *(u8 **)(s0 + 0x2C0) = p;
        if (p != 0) {
            func_L00_005F1180(p, obj);
        }
    }
    func_L01_00591BD8(obj, 1, -1);
    func_00591C70(obj, 0);
}

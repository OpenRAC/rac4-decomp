/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EAB210(u32 *out);
extern s32 func_01EA3B98(s32);
extern s32 func_01EA4970(void);
extern s32 func_01EA4B90(s32);
extern void func_01EA4E10(void);
extern s32 func_01EAAE98(void);
extern s32 func_01EA42D8(s32);
extern void func_01EABC10(s32);
extern s32 D_00167EFC[];
extern u8 *D_00167F38[];
extern s32 D_00167F58[];

// Runs the ready net object's two update hooks, then the net checks that may end the frame.
void func_01EA3E08(void) {
    u32 buf[4];
    u8 **pp;
    u8 *obj;
    s32 inner;

    func_01EAB210(buf);
    if (func_01EA3B98(1) != 0) {
        return;
    }
    if (D_00167F58[0] != 0) {
        func_01EABC10(D_00167EFC[0] + 0x10);
    }
    pp = &D_00167F38[0];
    obj = *pp;
    if (obj != 0) {
        inner = *(s32 *)(obj + 0x138);
        if (inner != 0 && *(s32 *)(inner + 0x454) == 1 && *(s32 *)(inner + 0x460) > *(s32 *)(inner + 0x404) && *(s32 *)(obj + 0x124) != 0) {
            ((void (*)(s32, u8 *))*(s32 *)(obj + 0x98))(inner, obj);
            ((void (*)(void))*(s32 *)(*pp + 0x9C))();
        }
    }
    if (func_01EA4970() != 0) {
        return;
    }
    if (func_01EA4B90(1) != 0) {
        return;
    }
    if (D_00167F38[0] != 0 && ((s32 (*)(void))*(s32 *)(D_00167F38[0] + 0xA0))() != 0) {
        return;
    }
    if (func_01EA42D8(func_01EAAE98()) != 0) {
        return;
    }
    func_01EA4E10();
}

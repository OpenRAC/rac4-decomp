#include "common.h"

extern void func_L01_00468E98(u8 *object);
extern void func_L01_00469638();
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L01_005A8A28(u8 *obj);

// Reset linked fields, run update calls and set state 2.
void func_L01_00468D48(u8 *object) {
    u8 *linked = *(u8 **)(object + 0xAC);

    *(s16 *)(linked + 0x4FE) = -1;
    linked[0x503] = 0;
    linked[0x500] = 0;
    linked[0x485] = 0;
    func_L01_00469638();
    func_L01_00468E98(object);
    func_L01_005A8A28(object);
    func_L01_00591BD8(object, 2, 2);
}

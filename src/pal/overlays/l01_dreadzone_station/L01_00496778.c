#include "common.h"

extern void func_L01_004967D8(u8 *object);
extern void func_L01_00497030();
extern void func_00474368(u8 *object, s32 new_state, s32 param);
extern void func_L01_005ACDA0(u8 *obj);

// Reset linked fields, run update calls and set state 2.
void func_L01_00496778(u8 *object) {
    u8 *linked = *(u8 **)(object + 0xAC);

    *(s16 *)(linked + 1238) = -1;
    linked[1240] = 0;
    linked[1241] = 0;
    linked[0x485] = 0;
    func_L01_00497030();
    func_L01_004967D8(object);
    func_L01_005ACDA0(object);
    func_00474368(object, 2, 2);
}

#include "common.h"

extern s32 func_L01_004968E8(void *);
extern void func_L01_005AF6A8(void *, f32);
extern void func_L01_00496848(void *, s64);

/* Initialize the cached action, update the object, and dispatch the action. */
void func_L01_004967E8(u8 *object) {
    u8 *state = *(u8 **)(object + 0xAC);
    if (*(s16 *)(state + 0x4D6) == -1)
        *(s16 *)(state + 0x4D6) = func_L01_004968E8(object);
    func_L01_005AF6A8(object, *(f32 *)(object + 0xF8));
    func_L01_00496848(object, *(s16 *)(state + 0x4D6));
}

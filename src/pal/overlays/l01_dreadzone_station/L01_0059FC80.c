#include "common.h"

extern void func_L01_0059FCA8(u8 *object, u8 *state, s32 first_motion,
                              s32 second_motion, s32 enabled, s32 player);

void func_L01_0059FC80(u8 *object, u8 *state, s32 first_motion, s32 second_motion, s32 player)
{
    func_L01_0059FCA8(object, state, first_motion, second_motion,
                      *(s32 *)(state + 0x12C) != 0, player);
}

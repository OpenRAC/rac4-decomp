#include "common.h"

extern void func_L01_0059B970(u8 *object, u8 *state, s32 first_motion,
                              s32 second_motion, s32 enabled, s32 player);

void func_L01_0059B948(u8 *object, u8 *state, s32 first_motion, s32 second_motion, s32 player)
{
    func_L01_0059B970(object, state, first_motion, second_motion,
                      *(s32 *)(state + 0x12C) != 0, player);
}

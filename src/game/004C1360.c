#include "common.h"

extern void func_00499CE0(s32 arg0);
extern s32 func_00505B20(void);
extern void func_00505D30(s32 arg0);
extern u8 D_30B358[];

/* Picks the entry at D_30B358 by func_00505B20 index, releases four of its words through func_00499CE0 and zeroes them */
void func_004C1360(void) {
    u8 *temp_s0;

    temp_s0 = (u8 *)((func_00505B20() * 0x258) + D_30B358);
    func_00505D30(0xF);
    func_00499CE0(*(s32 *)(temp_s0 + 0x14));
    *(s32 *)(temp_s0 + 0x14) = 0;
    func_00499CE0(*(s32 *)(temp_s0 + 0x18));
    *(s32 *)(temp_s0 + 0x18) = 0;
    func_00499CE0(*(s32 *)(temp_s0 + 0x1C));
    *(s32 *)(temp_s0 + 0x1C) = 0;
    func_00499CE0(*(s32 *)(temp_s0 + 0x20));
    *(s32 *)(temp_s0 + 0x20) = 0;
}

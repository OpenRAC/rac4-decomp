/* Not matching yet: BYTES 5/196 (tools/try_func.py func_004C2490 --diff). Not part of the build. */
#include "common.h"

extern s32 func_004978C0(s32 i);
extern s32 func_00499CA0(void *, s32);
extern void func_00499CE0(s32 arg0);
extern s32 func_004A1A60(void *arg0, s32 arg1);
extern s32 func_00505B20(void);
extern s32 func_00506120(s32, s32);
extern void *func_00510BE8(s32 arg0);
extern void *func_00548D28(s32, s32);
extern u8 D_1CD980[];
extern u8 D_221880[];
extern u8 D_30B7F8[];

void func_004C2490(void) {
    s32 index = func_00505B20();
    u8 *entry;
    u8 *slot;

    func_00510BE8(index);
    entry = D_30B7F8 + index * 0x74;
    slot = D_1CD980 + *((u8 *)func_00548D28(func_004978C0(*(s32 *)(entry + 0xC)), 0) + 0x29) * 8;
    if (*(s32 *)(entry + 0x70) != 0) {
        func_00499CE0(*(s32 *)(entry + 0x70));
        *(s32 *)(entry + 0x70) = 0;
    }
    *(s32 *)(entry + 0x70) = func_00499CA0(slot, -1);
    func_00506120(func_004A1A60(D_221880, 0x1D), *(s32 *)(entry + 0x70));
    *(s32 *)(entry + 8) &= ~4;
}

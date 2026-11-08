#include "common.h"

s32 func_00497980(s32);
extern s32 D_002217B8;

void func_004B9208(s32 arg0) {
    *(s32 *)((arg0 * 0x10) + (u8 *)&D_002217B8) = 2;
    func_00497980(0xC);
}

#include "common.h"

extern void func_00158C60(s32, s32, void *, s32, s32);

// Send a message with 3 arguments through func_00158C60
void func_001586F0(s32 arg0, s32 arg1, s32 arg2) {
    s32 payload[3];

    payload[0] = arg0;
    payload[1] = arg1;
    payload[2] = arg2;

    func_00158C60(0x4E, 0xC, payload, 0, 0);
}

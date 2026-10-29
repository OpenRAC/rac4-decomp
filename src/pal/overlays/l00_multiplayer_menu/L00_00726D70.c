#include "common.h"

// Counts up the word at +0x260; past 750 it resets it and sets the byte at +0x264.
void func_L00_00726D70(u8 *arg0) {
    if (++*(s32 *)(arg0 + 0x260) > 750.0f) {
        *(s32 *)(arg0 + 0x260) = 0;
        arg0[0x264] = 1;
    }
}

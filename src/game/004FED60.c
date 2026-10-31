#include "common.h"

extern void func_004FE9A0();

/* Sets the flag byte at +0x1B and, for arg1 1 or 2, the word at +8; calls func_004FE9A0 for arg1 2. */
void func_004FED60(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 0:
        arg0[0x1B] = 1;
        return;
    case 1:
        *(s32 *)(arg0 + 0x8) = 1;
        arg0[0x1B] = 1;
        break;
    case 2:
        *(s32 *)(arg0 + 0x8) = arg1;
        arg0[0x1B] = 1;
        func_004FE9A0();
        break;
    }
}

#include "common.h"

extern s32 D_002233A4;

u8 D_00220A02 = 0;

/* Clear two words of the object the global points at, and a flag byte. */
void func_L00_00709290(void) {
    (*(s32 *)((u8 *)D_002233A4 + 0x24)) = 0;
    (*(s32 *)((u8 *)D_002233A4 + 0x20)) = 0;
    D_00220A02 = 0;
}

#include "common.h"

extern void func_L00_0070C528(s32, s32, s32);
extern s32 func_L00_0070C718(s32, s32);

// Run func_L00_0070C528 for each of the 0x46 entries with the value
// func_L00_0070C718 returns for that entry and source.
void func_L00_0070C990(s32 object, s32 source) {
    s32 i;
    for (i = 0; i < 0x46; i++) {
        func_L00_0070C528(object, i, func_L00_0070C718(i, source));
    }
}

/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 D_002233A4[];
extern s32 func_L00_0076D220(s32, s32, s32);
extern void func_L00_0076E3C0(s32, s32, s32);

/* Looks up a menu item in the shared multiplayer table and opens the selected sub-screen. */
void func_L00_0076D100(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_L00_0076D220(*(s32 *)((u32)D_002233A4[0] + 0x40), arg0 + 0x1E4, 0);
    if (temp_v0 != 0) {
        func_L00_0076E3C0(temp_v0, arg0, arg1);
    }
}

#include "common.h"

/* Stores the result of func_004A0208 into the D_3098F0 slot for the current index, clears D_0021F7E8, then calls func_0049B1A0 with count 3. */
extern void func_0049B1A0(s32 param, s32 count);
extern s32 func_004A0208(s32 arg0);
extern s32 func_00505B20(void);
extern s32 D_3098F0[];
s8 D_0021F7E8 = 0;

void func_004B6E00(void) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_00505B20();
    temp_v0_2 = func_004A0208(temp_v0);
    D_0021F7E8 = 0;
    *(s32 *)((u8 *)D_3098F0 + temp_v0 * 0x1F8) = temp_v0_2;
    func_0049B1A0(temp_v0, 3);
}

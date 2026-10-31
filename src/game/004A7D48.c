#include "common.h"

extern s32 func_00498120(void);
extern s32 func_004981F8(s32 a0, s32 a1);
extern s32 *func_004A8C68(s32);
extern s32 D_308108[];

// Clear the word at 0x28 of record arg0 of D_308108; if it was the value func_00498120 returns, notify func_004981F8.
void func_004A7D48(s32 arg0) {
    s32 temp_s0;
    s32 *rec;

    rec = (s32 *)((u8 *)D_308108 + arg0 * 0xB8);
    temp_s0 = rec[10];
    rec[10] = 0;
    if (func_00498120() == temp_s0) {
        func_004981F8(arg0, *func_004A8C68(arg0));
    }
}

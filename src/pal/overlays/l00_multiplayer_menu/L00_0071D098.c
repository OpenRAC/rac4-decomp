#include "common.h"

extern s32 func_L00_007697C0(s32 identifier);

void func_L00_0071D098(void *unused, s64 from, s64 to)
{
    s32 sound = -1;
    if (from == 29 && to == 27)
        sound = 45;
    else if (from == 3 && to == 27)
        sound = 62;
    else if (from == 19 && to == 27)
        sound = 68;
    else if (from == 32 && to == 27)
        sound = 72;
    else if (from == 29 && to == 3)
        sound = 78;
    else if (from == 29 && to == 19)
        sound = 79;
    else if (from == 29 && to == 32)
        sound = 80;
    else if (from == 5 && to == 27)
        sound = 55;
    else if (from == 6 && to == 27)
        sound = 55;
    else if (from == 6 && (to == 8 || to == 5))
        sound = 59;
    else if (from == 7 && to == 27)
        sound = 55;
    else if (from == 8 && to == 27)
        sound = 55;
    else if (from == 9 && to == 27)
        sound = 55;
    else if (from == 9 && (to == 8 || to == 5))
        sound = 61;
    else if (from == 10 && (to == 8 || to == 5))
        sound = 57;
    else if (from == 36 && to == 27)
        sound = 74;
    else if (from == 16 && to == 15)
        sound = 75;
    else if (from == 29 && to == 16)
        sound = 77;
    if (sound != -1) {
        func_L00_007697C0(sound);
    }
}

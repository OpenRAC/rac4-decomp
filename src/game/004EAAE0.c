#include "common.h"
typedef struct Hero Hero;
extern Hero *func_00510BE8(s32);
extern s32 func_00515718(Hero *);
extern s32 D_0021DDB4;
extern void func_0043A118(s32, s32, s32, f32, f32, f32, f32);
extern void func_004E2C88(s32);
void func_004EAAE0(Hero *hero)
{
    if (!hero)
        hero = func_00510BE8(0);
    if (func_00515718(hero) == 5 && D_0021DDB4 == 8) {
        func_0043A118(0, 0, 3, 1.11002934f, 0.005f, 0.2f, 0.0f);
        func_004E2C88(1);
    }
}

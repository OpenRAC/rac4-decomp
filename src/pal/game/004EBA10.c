#include "common.h"
typedef struct Hero Hero;
extern Hero *func_00511CC0(s32);
extern s32 func_005167E8(Hero *);
extern s32 D_0021DE3C;
extern void func_0043A710(s32, s32, s32, f32, f32, f32, f32);
extern void func_004E3BB0(s32);
void func_004EBA10(Hero *hero)
{
    if (!hero)
        hero = func_00511CC0(0);
    if (func_005167E8(hero) == 5 && D_0021DE3C == 8) {
        func_0043A710(0, 0, 3, 1.11002934f, 0.005f, 0.2f, 0.0f);
        func_004E3BB0(1);
    }
}

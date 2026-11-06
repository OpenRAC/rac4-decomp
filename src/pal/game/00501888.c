#include "common.h"
typedef struct Pool Pool;
typedef s32 (*Resolver)(s32 context, s32 index);
extern Pool *func_005023A8(Pool *pool, s32 first, s32 last, s32 context, Resolver resolver);
extern s32 func_00501698(s32 context, s32 index);
extern u8 D_00335D50[], D_00335D68[], D_00335D80[], D_00335D98[], D_00335DB0[];
extern u8 D_003DD848[];
s32 D_0022211C = 0;
s32 D_00222120 = 0;
s32 D_00222124 = 0;
s32 D_00222128 = 0;
s32 D_0022212C = 0;
Pool *func_00501888(s32 category)
{
    if (!D_0022211C) {
        func_005023A8((Pool *)D_00335D50, 0, 0x3FF, 0, func_00501698);
        D_0022211C = 1;
    }
    if (!D_00222120) {
        func_005023A8((Pool *)D_00335D68, 0, 0x3FF, 1, func_00501698);
        D_00222120 = 1;
    }
    if (!D_00222124) {
        func_005023A8((Pool *)D_00335D80, 0, 0x3FF, 2, func_00501698);
        D_00222124 = 1;
    }
    if (!D_00222128) {
        func_005023A8((Pool *)D_00335D98, 0, 0x3FF, 3, func_00501698);
        D_00222128 = 1;
    }
    if (!D_0022212C) {
        func_005023A8((Pool *)D_00335DB0, 0, 0x3FF, 4, func_00501698);
        D_0022212C = 1;
    }
    return *(Pool **)((u32)D_003DD848 + ((u32)category << 2));
}

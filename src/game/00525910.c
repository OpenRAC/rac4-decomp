#include "common.h"

typedef struct Type2 {
    char _p0[0xBC];
    s16 fBC;
} Type2;

typedef struct Type1 {
    char _p0[0x2EF0];
    Type2 *f2EF0;
} Type1;

extern s32 func_004E1F90(s32 arg0, s32 arg1, void *arg2);

void func_00525910(Type1 *arg0)
{
    s32 id;

    switch (arg0->f2EF0->fBC) {
    case 0x251D: case 0x2581: id = 0x26; break;
    case 0x251E: case 0x2582: id = 0x27; break;
    case 0x251F: case 0x2583: id = 0x28; break;
    case 0x2520: case 0x2584: id = 0x29; break;
    case 0x2521: case 0x2585: id = 0x2A; break;
    case 0x2522: case 0x2586: id = 0x2B; break;
    case 0x2523: case 0x2587: id = 0x2C; break;
    case 0x2524: case 0x2588: id = 0x2D; break;
    case 0x2525: case 0x2589: id = 0x2E; break;
    case 0x2526: case 0x258A: id = 0x2F; break;
    case 0x2527: case 0x258B: id = 0x30; break;
    case 0x2528: case 0x258C: id = 0x31; break;
    case 0x2529: case 0x258D: id = 0x32; break;
    case 0x252A: case 0x258E: id = 0x33; break;
    case 0x252B: case 0x258F: id = 0x34; break;
    case 0x252C: case 0x2590: id = 0x35; break;
    case 0x252D: case 0x2591: id = 0x36; break;
    case 0x252E: case 0x2592: id = 0x37; break;
    case 0x252F: case 0x2593: id = 0x38; break;
    case 0x23F7: case 0x251C: case 0x2580: id = 0x13; break;
    default: id = 0x13; break;
    }
    func_004E1F90(id, 0, arg0->f2EF0);
}

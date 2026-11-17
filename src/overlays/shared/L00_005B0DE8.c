#include "common.h"

typedef struct {
    char pad[4];
    u32 f4;
    s64 f8;
} Type1;
typedef struct {
    char pad[0x150];
    s16 f150;
    s16 f152;
} Type2;
extern s32 D_1DFCF0[];
extern Type2 D_206A40[];
extern void func_L00_005B1178(s32, s32, s32, s32, u64);
extern void func_L00_00679210(s32, u64, s32);

/* Draws one banded region from a descriptor, bracketed by two command writes. */
void func_L00_005B0DE8(Type1 *arg0) {
    if (arg0->f8 != 0) {
        func_L00_00679210(0x42, arg0->f8 & 0xFF000000FFULL, 0);
    }
    if (arg0->f4 & 0xFF000000) {
        func_L00_00679210(0x4E, (D_1DFCF0[2] >> 13) | 0x1000000 | 0x100000000ULL, 0);
        func_L00_005B1178(0, D_206A40->f152, 0, D_206A40->f150, arg0->f4);
        func_L00_00679210(0x4E, 0x1000000 | (D_1DFCF0[2] >> 13), 0);
    }
    if (arg0->f8 != 0) {
        func_L00_00679210(0x42, 0x8000000044ULL, 0);
    }
}

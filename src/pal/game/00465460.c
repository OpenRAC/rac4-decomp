#include "common.h"

extern int D_0021EE54, D_0021EE58;
typedef struct Type1 {
    char p[8];
    s32 mode;
    u32 unknownC;
    int f10;
    char q[0x14];
    s32 threshold;
    char q2[0x198];
    int f1C4;
    int f1C8;
    int f1CC;
    int f1D0;
    s32 waiting;
    char r[0xC];
    int f1E4;
} Type1;
extern Type1 D_001719C8[];
int D_0021F1D4 = 5;
extern void func_00465338(int);
/* Reset the state counters and select state four. */
void func_00465460(void)
{
    if (!D_0021EE54 && !D_0021EE58)
        D_001719C8[0].f1E4 = 0;
    D_001719C8[0].f10 = 0;
    func_00465338(4);
    D_0021F1D4 = 5;
}

extern s32 D_0021DB60;
extern s32 D_002214E4;
extern u8 D_002214E8;
extern void (*D_003D8078[])(void);

void func_004653A0(void)
{
    s32 value = (u32)D_0021F1D4 - 1;
    s32 index;

    D_0021F1D4 = value > -1 ? value : 0;
    if (D_001719C8[0].waiting ||
        (D_001719C8[0].mode == 2 && D_001719C8[0].f10) ||
        D_001719C8[0].threshold > 0) {
        D_002214E8 = 1;
    }
    index = D_0021DB60;
    D_003D8078[index]();
    D_002214E4 = (u32)D_002214E4 + 1;
    if (D_0021DB60 != index) {
        D_002214E4 = 0;
    }
}

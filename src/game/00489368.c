#include "common.h"

typedef struct Type1 {
    char p0[0x2C];
    s16 f2C;
    char p2E[0x3C - 0x2E];
    s16 f3C;
    s16 f3E;
    char p40[0x44 - 0x40];
    s32 f44;
    s16 f48;
    char p4A[0x4C - 0x4A];
    s16 f4C;
    s16 f4E;
    char p50[0x6C - 0x50];
    s32 f6C;
    char p70[0x74 - 0x70];
    s16 f74;
    s16 f76;
    char p78[0xBC - 0x78];
    s32 fBC;
    char pC0[0xC4 - 0xC0];
    s16 fC4;
    s16 fC6;
} Type1;

extern s32 func_00157F98(void);
extern void func_004535E0(s32);
extern void func_00489478(void);
extern void func_004894D8(void *);
extern void func_004E0858(void);
extern Type1 D_00206948[];
extern s32 D_0020698C[];
extern s32 D_0021F350;
s32 D_0021F344 = 0;

/* Run the wait loops until the state clears, then reset the state block. */
void func_00489368(void)
{
    D_0021F344 = 1;
    func_004E0858();
    do {
        func_004535E0(D_0021F350);
    } while (func_00157F98() != 0);
    D_00206948[0].f4E = 5;
    func_00489478();
    while (D_00206948[0].f4E != 0) {
        func_004894D8(D_0020698C);
        do {
            func_004535E0(D_0021F350);
        } while (func_00157F98() != 0);
    }
    D_00206948[0].f4E = 0;
    D_00206948[0].f4C = 0;
    D_00206948[0].f44 = 0;
    if (D_00206948[0].f3C != -1) {
        D_00206948[0].f48 = D_00206948[0].f3C;
    }
    D_00206948[0].f76 = 0;
    D_00206948[0].f74 = 0;
    D_00206948[0].f6C = 0;
    D_00206948[0].fC6 = 0;
    D_00206948[0].fC4 = 0;
    D_00206948[0].fBC = 0;
    D_00206948[0].f2C = 0;
    D_00206948[0].f3C = -1;
    D_00206948[0].f3E = -1;
    D_0021F344 = 0;
}

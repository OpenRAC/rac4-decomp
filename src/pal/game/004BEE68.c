#include "common.h"

/* Retail rows have stride 0x304; the flag byte is at offset 0x300. */
typedef struct Progress {
    u8 unknown0[0x300];
    u8 flags;
    u8 unknown301[3];
} Progress;

typedef struct Totals {
    u8 unknown0[0xC];
    s32 points;
    u8 unknown10[0x11];
    u8 award21;
    u8 unknown22;
    u8 award23;
    u8 award24;
    u8 award25;
} Totals;

extern Progress D_001F8878[];
extern Totals D_00171BC0;
extern u32 D_00171C94[];
extern s32 D_0021DE98;
extern s32 func_0045E478(s16, s16);

static inline u32 progressAddress(u32 base, u32 offset)
{
    return base + offset;
}

static inline s32 flagBit(s32 flags, s32 bit)
{
    return (flags >> bit) & 1;
}

void func_004BEE68(void)
{
    s32 i;
    for (i = 2; i < 15; i++) {
        Progress *progress = (Progress *)progressAddress(
            (u32)D_001F8878, ((i - 1) % 20) * sizeof(Progress));
        if (flagBit(progress->flags, 2) && !flagBit(progress->flags, 3))
            func_0045E478(0x2FB4, 0x689);
    }
    if (flagBit(D_001F8878[13].flags, 3) && D_0021DE98 != 15) {
        func_0045E478(0x3310, 0x75B);
        if (D_00171C94[0] & 0x20000000)
            func_0045E478(0x2962, 0x2D9);
    }
    if (flagBit(D_001F8878[1].flags, 3)) {
        if (!flagBit(D_001F8878[3].flags, 1))
            func_0045E478(0x2F4E, 0x630);
        func_0045E478(0x2F98, 0x66E);
    }
    if (flagBit(D_001F8878[13].flags, 1) &&
        +!flagBit(D_001F8878[13].flags, 3))
        func_0045E478(0x3379, 0x7C4);
    if (flagBit(D_001F8878[10].flags, 1) &&
        +!flagBit(D_001F8878[10].flags, 3))
        func_0045E478(0x333C, 0x787);
    if (flagBit(D_001F8878[6].flags, 1) &&
        +!flagBit(D_001F8878[6].flags, 3))
        func_0045E478(0x2F37, 0x61A);
    if (flagBit(D_001F8878[5].flags, 1) &&
        +!flagBit(D_001F8878[5].flags, 3))
        func_0045E478(0x2F34, 0x618);
    if (flagBit(D_001F8878[4].flags, 1) &&
        +!flagBit(D_001F8878[4].flags, 3))
        func_0045E478(0x2F30, 0x614);
    if (flagBit(D_001F8878[3].flags, 1) &&
        +!flagBit(D_001F8878[3].flags, 3))
        func_0045E478(0x2F33, 0x617);
    if (D_00171BC0.points >= 15000 && D_00171BC0.award23 >= 4)
        func_0045E478(0x2F43, 0x625);
    if (D_00171BC0.points >= 50000 && D_00171BC0.award21 >= 2)
        func_0045E478(0x2F4A, 0x62C);
    if (D_00171BC0.points >= 100000 && D_00171BC0.award24 >= 2)
        func_0045E478(0x2FA2, 0x677);
    if (D_00171BC0.points >= 150000 && D_00171BC0.award25 >= 2)
        func_0045E478(0x2F91, 0x667);
}

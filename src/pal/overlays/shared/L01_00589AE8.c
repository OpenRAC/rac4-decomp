#include "common.h"

typedef struct Slot {
    u8 pad0[8];
    u8 x8;
    u8 x9;
    u8 padA[2];
} Slot;

typedef struct Inf {
    u8 pad0[0x24];
    s32 x24;
    s32 x28;
    u8 pad2C[5];
    u8 x31[0x27];
    u8 x58[1];
} Inf;

typedef struct Stats {
    s32 x0;
    u8 pad4[8];
    s32 xC;
    u8 pad10[2];
    u16 x12;
    u8 pad14[4];
    s32 x18;
    u8 pad1C[5];
    u8 x21;
    u8 x22;
    u8 x23;
    u8 x24;
    u8 x25;
    u8 pad26[0x10];
    s16 x36;
} Stats;

extern u8 D_001F8878[];
extern Stats D_00171BC0;
extern s32 D_0021DE98;
s32 D_0021EC58 = 0;

extern s32 func_0054C070(s32 a, s32 b);
extern Inf *func_0054BF00(s32 a);
extern void func_L01_006C6AD0(u8 *p);
extern void func_L01_006C6C38(u8 *p);
extern s32 func_0046BBF0(s32 a, s32 b);
extern s32 func_0046BC78(s32 a, s32 b);

// Updates the counters in D_00171BC0 for the current level and slot (D_0021DE98, D_0021EC58).
void func_L01_00589AE8(void) {
    Inf *p;
    s32 k;
    s32 n;

    p = func_0054BF00(func_0054C070(D_0021DE98, D_0021EC58));
    if (((Slot *)((D_0021DE98 - 1) % 20 * 0x304 + D_0021EC58 * 12 + D_001F8878))->x9 == 0) {
        k = p->x24;
        if (k == 1) {
            D_00171BC0.x21++;
        } else if (k == 2) {
            D_00171BC0.x22++;
        } else if (k == 3) {
            D_00171BC0.x23++;
        } else if (k == 4) {
            D_00171BC0.x24++;
        } else if (k == 5) {
            D_00171BC0.x25++;
        }
        if (D_00171BC0.x36 < p->x28) {
            D_00171BC0.x12 = p->x28;
            D_00171BC0.x36 = p->x28;
            D_00171BC0.x18 |= 1 << p->x28;
        }
        func_L01_006C6AD0(p->x31);
        func_L01_006C6C38(p->x58);
    }
    n = func_0046BBF0(D_0021DE98, D_0021EC58);
    if (n != 0) {
        D_00171BC0.xC += n;
    }
    n = func_0046BC78(D_0021DE98, D_0021EC58);
    if (n != 0) {
        D_00171BC0.x0 += n;
    }
}

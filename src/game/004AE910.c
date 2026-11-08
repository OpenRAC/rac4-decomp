#include "common.h"
typedef struct { s32 a; s32 b; u8 c; u8 pad[3]; } Entry;
typedef struct { s32 a; s32 b; } Pair;
typedef struct { s32 pad[10]; s32 active[4]; s32 pad2[4]; s32 timer[4]; } State;
extern Entry D_003D92A0[];
extern u8 D_003092A0[];
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_0021DE10;
extern s32 D_002216C0;
extern s32 D_00221218;
extern s32 D_001F1400[];
extern u32 D_0021DA70;
s32 D_0021F73C = 0;
extern void func_004493E8(s32 *a, void (*b)(void *), s32 c);
extern s32 func_004534D0(s32 *arg0);
extern void func_0045D950(s32, s32, s32);
extern void func_0045DA70(s32, s32, s32, s32);
extern void func_0045DAC0(s32, s32, s32, s32);
extern s32 func_0047C3D0(Pair *out, s32 i, s32 b);
extern void func_0047C0F0(void *);
extern u8 *func_0047D4E8(void);
extern s32 func_00505B20(void);

void func_004AE910(void)
{
    State *flags = (State *)(D_003092A0 + func_00505B20() * 0x64);
    Pair cur;
    s32 i;

    if (D_0021EDD4 == 0 && D_0021EDD8 == 0) {
        if (func_004534D0(&D_002216C0)) {
            D_002216C0 = 0x14;
            for (i = 0; i < 4; i++) {
                if (flags->active[i] != 0)
                    continue;
                if (func_0047C3D0(&cur, i, D_003D92A0[i].b)) {
                    switch (cur.a) {
                    case 2:
                        func_0045DA70(0x3460, 0x7F1, 0x4B0, 2);
                        break;
                    case 10:
                        if ((u32)D_001F1400[0x4ED0 / 4] < D_0021DA70)
                            D_001F1400[0x4ED0 / 4] = D_0021DA70;
                        break;
                    case 11:
                        if (D_0021DA70 - D_001F1400[0x4ED0 / 4] < 6000)
                            func_0045D950(0x333A, 0x785, 2);
                        break;
                    case 5:
                        func_0045DA70(0x292A, 0x2A1, 0x1A4, 2);
                        break;
                    case 6:
                        func_0045DA70(0x292E, 0x2A5, 0x258, 2);
                        break;
                    case 12:
                        break;
                    case 9:
                        if (D_0021DE10 != 1)
                            func_0045D950(0x2987, 0x2FE, 2);
                        func_0045DAC0(0x3202, 0x709, 0x708, 2);
                        break;
                    }
                    if (D_003D92A0[i].a != cur.a || D_003D92A0[i].b != cur.b) {
                        D_003D92A0[i].a = cur.a;
                        D_003D92A0[i].b = cur.b;
                        if (D_003D92A0[i].a != 1)
                            flags->timer[i] = 0x5A;
                    }
                    if (D_003D92A0[i].a == 9) {
                        if (func_0047D4E8()[3] == 0)
                            flags->timer[i] = 0x5A;
                    }
                } else {
                    D_003D92A0[i].a = 0;
                    D_003D92A0[i].b = 0;
                    flags->timer[i] = 0;
                }
            }
        }
        if (D_003D92A0[3].a == 2)
            func_004493E8(&D_00221218, func_0047C0F0, D_003D92A0[3].b);
    }
    D_0021F73C |= 2;
}

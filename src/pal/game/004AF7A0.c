#include "common.h"
#include "pal/record_001F1480.h"
typedef struct { s32 a; s32 b; u8 c; u8 pad[3]; } Entry;
typedef struct { s32 a; s32 b; } Pair;
typedef struct { s32 pad[10]; s32 active[4]; s32 pad2[4]; s32 timer[4]; } State;
extern Entry D_003D9318[];
extern u8 D_003093A0[];
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 D_0021DE98;
extern s32 D_002217C0;
extern s32 D_00221318;
extern u32 D_0021DAF0;
s32 D_0021F73C = 0;
extern void func_00449A28(s32 *a, void (*b)(void *), s32 c);
extern s32 func_00453CE8(s32 *arg0);
extern void func_0045E168(s32, s32, s32);
extern s32 func_0047CD08(Pair *out, s32 i, s32 b);
extern void func_0047CA28(void *);
extern u8 *func_0047DE20(void);
extern s32 func_00506BB8(void);

void func_004AF7A0(void)
{
    State *flags = (State *)(D_003093A0 + func_00506BB8() * 0x64);
    Pair cur;
    s32 i;

    if (D_0021EE54 == 0 && D_0021EE58 == 0) {
        if (func_00453CE8(&D_002217C0)) {
            D_002217C0 = 0x14;
            for (i = 0; i < 4; i++) {
                if (flags->active[i] != 0)
                    continue;
                if (func_0047CD08(&cur, i, D_003D9318[i].b)) {
                    switch (cur.a) {
                    case 2:
                        func_0045E288(0x3460, 0x7F1, 0x3E8, 2);
                        break;
                    case 10:
                        if ((u32)D_001F1480[1681].f4 < D_0021DAF0)
                            D_001F1480[1681].f4 = D_0021DAF0;
                        break;
                    case 11:
                        if (D_0021DAF0 - D_001F1480[1681].f4 < 0x1388)
                            func_0045E168(0x333A, 0x785, 2);
                        break;
                    case 5:
                        func_0045E288(0x292A, 0x2A1, 0x15E, 2);
                        break;
                    case 6:
                        func_0045E288(0x292E, 0x2A5, 0x1F4, 2);
                        break;
                    case 12:
                        break;
                    case 9:
                        if (D_0021DE98 != 1)
                            func_0045E168(0x2987, 0x2FE, 2);
                        func_0045E2D8(0x3202, 0x709, 0x5DC, 2);
                        break;
                    }
                    if (D_003D9318[i].a != cur.a || D_003D9318[i].b != cur.b) {
                        D_003D9318[i].a = cur.a;
                        D_003D9318[i].b = cur.b;
                        if (D_003D9318[i].a != 1)
                            flags->timer[i] = 0x5A;
                    }
                    if (D_003D9318[i].a == 9) {
                        if (func_0047DE20()[3] == 0)
                            flags->timer[i] = 0x5A;
                    }
                } else {
                    D_003D9318[i].a = 0;
                    D_003D9318[i].b = 0;
                    flags->timer[i] = 0;
                }
            }
        }
        if (D_003D9318[3].a == 2)
            func_00449A28(&D_00221318, func_0047CA28, D_003D9318[3].b);
    }
    D_0021F73C |= 2;
}

#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(u8 *);
    s32 (*f20)(u8 *);
} Type1;

typedef struct {
    u8 pad0[0x68];
    s32 f68;
} Type2;

extern void *func_0046D428(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00472560(s32 a0);
extern void func_00497000(s32 a0);
extern u8 D_001723B0[];
extern u8 *D_0021DFF0;
extern u8 *D_002213F4;
extern u8 *D_00221410;
extern Type2 D_00354630[];

void func_005471B0(void) {
    u8 *list[16];
    s32 count;
    Type1 *t2;
    u8 *q;

    if (D_0021DFF0[0x23] == 0) {
        return;
    }
    if (D_001723B0[0] != 0) {
        u8 **sel;
        u8 *p;
        s32 n;
        Type1 *t;
        if (D_00354630[0].f68 & 1) {
            return;
        }
        n = 0;
        for (p = D_002213F4; p != D_00221410; p += 0x100) {
            if (*(s16 *)(p + 0xBC) == 0x2075 && (*(u8 **)(p + 0xAC))[0x2DD] != 0) {
                list[n] = p;
                n++;
            }
        }
        if (n != 0) {
            sel = &list[func_00472560(n)];
            if (*sel != 0) {
                t = func_0046D428(0x2075, 0, 0x24);
                if (t != 0 && t->f1C != 0 && t->f1C(*sel) == 1) {
                    D_00354630[0].f68--;
                    if (D_00354630[0].f68 < 0) {
                        D_00354630[0].f68 = 0;
                    }
                    func_00497000(D_00354630[0].f68);
                }
            }
        }
    }
    if (D_00354630[0].f68 & 1) {
        return;
    }
    count = 0;
    t2 = func_0046D428(0x2075, 0, 0x24);
    if (t2 != 0 && t2->f20 != 0) {
        for (q = D_002213F4; q != D_00221410; q += 0x100) {
            if (*(s16 *)(q + 0xBC) == 0x2075) {
                if (t2->f20(q) == 0) {
                    count++;
                }
            }
        }
    }
    D_00354630[0].f68 = count;
    func_00497000(count);
}

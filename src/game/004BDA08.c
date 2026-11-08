#include "common.h"

extern s32 func_0045E038(s32);
extern void func_0046A290(s32 arg0);
extern void *func_0046D428(s32, s32, s32);
extern void func_00497980(s32 arg0);
extern void func_00498CF8(void);
extern void func_0049B1A0(s32 arg0, s32 arg1);
extern void func_0049B2F8(s32 arg0, s32 arg1);
extern void func_0049E790(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);
extern void func_004BDD90(void);
extern s32 func_004BEEA0(s32);
extern s32 func_00505B20(void);
extern void func_004BDD60(s32);
extern s32 D_0021F198;
extern s32 D_0021DE10;
extern u8 D_001F87F0[];
extern s32 D_00241B00[];
extern char D_0030B358[];

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    s32 w8;
} Type1;

typedef struct {
    s32 unk0;
    s32 unk4;
    Type1 *p;
    s32 pad[3];
} Type2;

s32 D_0021F934 = 0;
u8 D_0021F938 = 0;
u8 D_0021F939 = 0;
u8 D_0021F93A = 0;

/* Handles the current slot's selected entry: rejects, cancels or confirms it and opens the matching dialog. */
void func_004BDA08(void) {
    s32 slot;
    char *rec;
    char *sub;
    Type2 *e;
    s32 idx;
    Type1 *p;
    s32 saved;
    s32 mode;
    s32 state;
    s32 count;
    s32 n;
    s32 a;
    s32 b;
    s32 r;
    void **obj;
    void (*fn)(void);

    slot = func_00505B20();
    rec = D_0030B358 + slot * 600;
    sub = rec + 0x1EC;
    if (*(s32 *)(sub + 0x50) <= 0) {
        return;
    }
    idx = *(s32 *)(sub + 0x54);
    if (idx < 0) {
        e = 0;
    } else {
        e = (Type2 *)(*(s32 *)(sub + 0x34) + idx * 0x18);
    }
    p = e->p;
    saved = *(s32 *)(rec + 0x240);
    if (p->b0 != 0) {
        func_00497980(4);
        return;
    }
    n = 20;
    a = D_001F87F0[0x69];
    if (a > 0) {
        b = D_001F87F0[0x1C5];
    }
    if (a <= 0 || b <= 0) {
        func_00498CF8();
        D_0021F93A = 0;
        D_0021F939 = 0;
        D_0021F938 = 0;
        func_0049B2F8(slot, -1);
        return;
    }
    count = 1;
    mode = D_0021DE10 % n;
    state = D_0021F198;
    if (p->w8 == 0) {
        count = p->w4;
    }
    func_00497980(7);
    if ((mode == 1 && !((state < 9 && D_00241B00[0] == 0) || p->w8 != 1 || p->w4 != 0))
        || (mode != 1 && p->w8 == 1)) {
        func_0049E790(4, (const char *)func_0045E038(0x362E), func_004BDD60, 3, 0, 0, 0, -1.0f);
        return;
    }
    if (p->b2 == 0 || (mode == 1 && p->w8 == 1 && p->w4 != 0) || mode == count % 20) {
        D_0021F934 = saved;
        D_0021F938 = 1;
        D_0021F939 = 1;
        if (p->w8 == 1) {
            r = func_004BEEA0(count);
            if (mode == 1 && (D_0021F198 < 8 || D_00241B00[0] != 0)) {
                func_0049B1A0(slot, 14);
                return;
            }
            obj = func_0046D428(0x20A3, 0x10, 0x1C);
            if (obj != 0) {
                fn = (void (*)(void))obj[6];
                if (fn != 0) {
                    fn();
                }
            }
            func_0046A290(r);
            func_004BDD90();
        } else {
            func_0049B1A0(slot, 2);
        }
    } else if (p->w8 == 1) {
        func_0049E790(slot, (const char *)func_0045E038(0x362E), func_004BDD60, 3, 0, 0, 0, -1.0f);
    } else {
        func_0049E790(slot, (const char *)func_0045E038(0x3056), func_004BDD60, 3, 0, 0, 0, -1.0f);
    }
}

#include "common.h"

extern u8 D_00240000[];
extern u8 D_00171DB8[];
extern u8 D_004C9208[];
extern s32 D_00269EA0[];
s32 D_0021E9C8 = 0;
s32 D_0021E9CC = 0;
s32 D_0021E9D0 = 0;
extern s32 D_0021E9EC;
extern s32 D_0021E9F0;
extern s32 D_0021EB00;

void func_L00_005D4A40(void);
void func_L00_005D4B40(u8 *);
void func_L00_005D4ED0(void *, void *);
void func_L00_005D4FA0(u8 *, s32 *);
void func_L00_005D50B8(u8 *, s32 *);
void *func_0011A518(void *, s32, unsigned int);
void func_L00_005D51C0(u8 *, u8 *, s32 *);
void func_L00_005D5290(u8 *, s32 *, s32);
void func_L00_005D55C8(s32 *);
void func_L00_005D5710(u8 *, u8 *, s32 *);
void func_L00_005D57E8(u8 *, u8 *, s32 *);
void func_L00_005D58D0(u8 *, u8 *, s32 *, s32, s32);
s32 func_L00_005D2428(s32, s32, s32);
void func_L00_005D59C0(u8 *, u8 *, s32 *);
void func_L00_005D5A28(u8 *, u8 *);
void func_L00_005BDCB8(u8 *, s32, s32);
void func_L00_005D5A80(u8 *, s32 *, s32 *);
void func_L00_005D5BE8(u8 *, u8 *, s32 *);
void func_L00_005D5CC0(u8 *, s32 *);
void func_L00_005D5D88(u8 *, s32 *);
void func_L00_005D5ED8(u8 *, s32 *);
void func_L00_005D5FB8(u8 *, s32 *);
void func_L00_005D6080(u8 *, s32 *);
void func_L00_005D6148(u8 *, s32 *);
void func_L00_005D6218(u8 *, s32 *);
void func_L00_005D6280(s32 *);
void func_L00_005D62E8(u8 *, s32 *);
void func_L00_005AE320(void);
void func_L00_005BDDC8(s32, s32, s32);

static inline u8 *level(void) {
    return D_00240000;
}

// Add PAL C for func_L00_005D6880
s32 func_L00_005D6880(u8 *h, s32 unused, s32 cur) {
    u8 buf[0x80];
    s32 pos;
    s32 aux;
    u8 *a;
    u8 *b;
    s32 i;
    s32 size;
    s32 end;

    pos = cur;
    aux = 0;
    a = h + *(s32 *)(h + 0x40);
    b = h + *(s32 *)(h + 0x44);
    func_L00_005D4A40();
    if (*(s32 *)(h + 0) != 0) {
        func_L00_005D4B40(h + *(s32 *)(h + 0));
    }
    *(s32 *)(level() + 0x80) = pos;
    if (*(s32 *)(h + 0xC) != 0) {
        if (D_00171DB8[0xBD] == 0) {
            func_L00_005D4ED0(h + *(s32 *)(h + 0x10), &pos);
        } else {
            func_L00_005D4ED0(h + *(s32 *)((D_00171DB8[0xBD] << 2) + h + 0xC), &pos);
        }
    }
    if (*(s32 *)(h + 0x4) != 0) {
        func_L00_005D4FA0(h + *(s32 *)(h + 0x4), &pos);
    }
    if (*(s32 *)(h + 0x8) != 0) {
        func_L00_005D50B8(h + *(s32 *)(h + 0x8), &pos);
    }
    *(s32 *)(level() + 0x8C) = pos;
    if (*(s32 *)(h + 0x30) != 0) {
        func_0011A518(buf, 0, 0x80);
        func_L00_005D51C0(h + *(s32 *)(h + 0x30), buf, &pos);
        *(s32 *)(level() + 0x8C) = pos;
        func_L00_005D5290(h + *(s32 *)(h + 0x30), &aux, 0);
        func_L00_005D55C8(&pos);
    }
    if (*(s32 *)(h + 0x40) != 0 && *(s32 *)(h + 0x44) != 0) {
        func_L00_005D5710(a, b, &pos);
        func_L00_005D57E8(a, b, &pos);
        *(s32 *)(level() + 0x94) = pos;
        func_L00_005D58D0(a, b, &pos, 0, 0);
        size = pos;
        *(s32 *)(level() + 0x98) = size;
        end = size;
        size -= *(s32 *)(level() + 0x94);
        D_0021E9F0 = size;
        pos = func_L00_005D2428(size, 1, end);
    }
    if (*(s32 *)(h + 0x3C) != 0) {
        func_L00_005D59C0(h + *(s32 *)(h + 0x3C), a, &aux);
    }
    if (*(s32 *)(h + 0x48) != 0) {
        func_L00_005D5A28(h + *(s32 *)(h + 0x48), a);
    }
    *(s32 *)(level() + 0x60) = pos;
    pos = func_L00_005D2428(D_0021E9C8, 0x10, pos);
    *(s32 *)(level() + 0x74) = pos;
    pos = func_L00_005D2428(D_0021E9CC, 0x10, pos);
    *(s32 *)(level() + 0x78) = pos;
    pos = func_L00_005D2428(D_0021E9D0, 0x10, pos);
    func_L00_005BDCB8(D_004C9208, 0, 0x110);
    if (*(s32 *)(h + 0x34) != 0) {
        func_L00_005D5A80(h + *(s32 *)(h + 0x34), &pos, &aux);
    }
    for (i = 0; i < 0x110; i++) {
        if (D_00269EA0[i] != 0) {
            D_004C9208[i] = 1;
        }
    }
    if (*(s32 *)(h + 0x38) != 0) {
        func_L00_005D5BE8(h + *(s32 *)(h + 0x38), a, &pos);
    }
    *(s32 *)(level() + 0x9C) = pos;
    if (*(s32 *)(h + 0x5C) != 0) {
        func_L00_005D5CC0(h + *(s32 *)(h + 0x5C), &pos);
    }
    if (*(s32 *)(h + 0x60) != 0) {
        func_L00_005D5D88(h + *(s32 *)(h + 0x60), &pos);
    }
    if (*(s32 *)(h + 0x58) != 0) {
        func_L00_005D5ED8(h + *(s32 *)(h + 0x58), &pos);
    }
    if (*(s32 *)(h + 0x4C) != 0) {
        func_L00_005D5FB8(h + *(s32 *)(h + 0x4C), &pos);
    }
    if (*(s32 *)(h + 0x50) != 0) {
        func_L00_005D6080(h + *(s32 *)(h + 0x50), &pos);
    }
    if (*(s32 *)(h + 0x54) != 0) {
        func_L00_005D6148(h + *(s32 *)(h + 0x54), &pos);
    }
    if (*(s32 *)(h + 0x6C) != 0) {
        func_L00_005D6218(h + *(s32 *)(h + 0x6C), &pos);
    }
    func_L00_005D6280(&pos);
    if (h + (*(s32 *)(h + 0x74) << 7) != 0) {
        func_L00_005D62E8(h + *(s32 *)(h + 0x74), &pos);
    }
    func_L00_005AE320();
    func_L00_005BDDC8(*(s32 *)(level() + 0x90), D_0021EB00, D_0021E9EC);
    func_L00_005BDDC8(*(s32 *)(level() + 0x98), *(s32 *)(level() + 0x94), D_0021E9F0);
    return pos;
}

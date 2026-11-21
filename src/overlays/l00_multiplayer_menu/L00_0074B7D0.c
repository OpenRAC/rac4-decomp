#include "common.h"

extern s32 func_L00_0071B8E8(void *arg0, s32 arg1, s32 arg2);
extern void func_L00_007647B0(s32 arg0);

typedef struct Vt {
    u8 p0[0x20];
    void (*f20)(void *, s32, s32);
    u8 p24[0x70];
    s32 (*f94)(void *);
    u8 p98[0xC];
    void (*fA4)(void *, s32);
    s32 (*fA8)(void *);
} Vt;

typedef struct Item {
    u8 p0[0x58];
    Vt *f58;
} Item;

typedef struct Obj {
    u8 p0[0xB0];
    Item *slots[0x60];
    s32 f230;
    u8 p234[0x3C];
    s32 f270;
    u8 p274[0x470];
    s32 f6E4;
} Obj;

/* Handles a menu input event: opens a slot for events 3 and 4, or tests and selects an entry for events 1 and 2. */
s32 func_L00_0074B7D0(Obj *arg0, s32 arg1) {
    Item *item;
    Item **slots;
    Item **p;
    s32 temp;

    if ((u32)(arg1 - 3) < 2) {
        if (arg0->f230 == 0xC) {
            func_L00_007647B0(0x77);
            func_L00_0071B8E8(arg0, arg0->f270, 0);
            item = arg0->slots[12];
            item->f58->f20(item, 2, 0);
            return 1;
        }
        if (arg0->f6E4 > 0) {
            func_L00_007647B0(0x76);
            item = arg0->slots[12];
            item->f58->f20(item, 4, 0);
            func_L00_0071B8E8(arg0, 0xC, 0);
            return 1;
        }
    }
    if (arg0->f230 != 0xC) {
        return 0;
    }
    if (arg1 == 1) {
        item = arg0->slots[12];
        slots = arg0->slots;
        if (item->f58->fA8(item) == 0) {
            func_L00_007647B0(0x79);
            p = &slots[arg0->f230];
            item = *p;
            item->f58->fA4(item, arg0->f6E4 - 1);
            return 1;
        }
    }
    if (arg1 == 2) {
        item = arg0->slots[arg0->f230];
        temp = item->f58->fA8(item);
        item = arg0->slots[arg0->f230];
        if (temp != item->f58->f94(item) - 1) {
            return 0;
        }
        func_L00_007647B0(0x79);
        item = arg0->slots[arg0->f230];
        item->f58->fA4(item, 0);
        return 1;
    }
    return 0;
}

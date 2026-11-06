#include "common.h"
typedef struct Dialog {
    u8 pad00[0x10];
    s32 active;
    u8 pad14[4];
    s16 choice;
    u8 pad1A[0x1AA];
    s32 phase;
    u32 pad1C8;
    s32 index;
    s32 selection;
} Dialog;
typedef struct Item {
    u8 disabled;
    u8 pad01[3];
    const char *text;
    s32 value;
} Item;
extern Dialog D_001719C8;
extern Item D_003D9158[];
extern void func_00466B58(void);
extern void func_004A0F28(s32, s32);
extern const char *func_0045E850(s32);
extern void func_004A0398(s32, f32, f32, f32, f32);
extern void func_004A0F10(s32, s32);
extern void func_004A0D78(s32, s32, const Item *);
extern void func_004A0028(s32, void (*)(void));
extern void func_004A3060(void);
extern s32 func_004E3138(s32, s32, void *);
extern s32 func_004E17B8(void);
void func_004A2E90(s32 context)
{
    Item *rows;
    D_001719C8.active = 0;
    if (D_001719C8.index < 0) {
        D_001719C8.selection = 0;
        D_001719C8.index = 7;
    }
    /* 4A2F08 BGEZ continues waiting while the index is nonnegative. */
    while (D_001719C8.phase != 2 || D_001719C8.index >= 0) {
        func_00466B58();
    }
    if (D_001719C8.choice >= -1) {
        func_004A0F28(context, 1);
    } else {
        func_004A0F28(context, 0);
    }
    rows = D_003D9158;
    rows[0].text = func_0045E850(0x23B5);
    /* 4A2F84 stores this text result in A0398's call delay slot. */
    rows[1].text = func_0045E850(0x144);
    func_004A0398(context, 0.685f, 0.28f, 0.37109375f, 0.0480769239f);
    func_004A0F10(context, 0);
    func_004A0D78(context, 2, rows);
    func_004A0028(context, func_004A3060);
    func_004E3138(7, 0, NULL);
    func_004E17B8();
}

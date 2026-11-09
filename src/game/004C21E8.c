#include "common.h"
typedef struct {
    s32 a, b, flags, selection;
    char pad10[0xC];
    char text1[0x10];
    char text2[0x8];
    char text3[0x40];
} Entry;
typedef struct {
    char pad[0xA];
    s16 label;
} Info2;
extern Entry D_0030B7F8[];
extern char D_0021F9A8[];
extern char D_0021F9B0[];
extern s32 D_00221880;
extern s32 D_00221888;
extern s32 func_0011D920(char *, char *, ...);
extern s32 func_0045E038(s32);
extern s32 func_004978C0(s32);
extern void func_00497AE0(s32, s32, s32, f32, f32);
extern s32 func_00498270(s32, s32, s32, s32, s32);
extern s32 func_00498918(s32, s32);
extern s32 func_004A1A60(s32 *, s32);
extern s32 func_00505238(s32, s32);
extern s32 func_005056C8(s32, s32, s32, s32, s32);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32);
extern s16 func_00547D58(s32, s32);
extern s32 func_00547E00(s32, s32);
extern s16 func_00547E30(s32, s32);
extern f32 func_00548280(s32, s32);
extern s32 func_00548518(s32, s32);
extern Info2 *func_00548D28(s32, s32);

void func_004C21E8(void)
{
    s32 index = func_00505B20();
    Entry *p = D_0030B7F8 + index;
    s32 sel = func_004978C0(p->selection);
    s32 obj = (s32)func_00510BE8(index);
    s32 a, b;

    func_0011D920(p->text1, D_0021F9A8, func_00547E00(*(s32 *)(obj + 0x26E4), sel), func_00547E30(*(s32 *)(obj + 0x26E4), sel));
    func_0011D920(p->text3, D_0021F9B0, func_00547D58(*(s32 *)(obj + 0x26E4), sel) + 1);
    if (sel == 8) {
        s32 h = func_004A1A60(&D_00221880, 0x48);
        func_00505238(h, func_0045E038(0x34B2));
        func_0011D920(p->text2, D_0021F9B0, func_00548518(*(s32 *)(obj + 0x26E4), 8));
    } else {
        s32 h = func_004A1A60(&D_00221880, 0x48);
        func_00505238(h, func_0045E038(0x239F));
        func_0011D920(p->text2, D_0021F9B0, func_00548518(*(s32 *)(obj + 0x26E4), sel));
    }
    func_00505238(func_004A1A60(&D_00221880, 0x3F), func_00498270(index, sel, 1, 1, 1));
    func_00505238(func_004A1A60(&D_00221888, 0x53), func_0045E038(func_00548D28(sel, 0)->label));
    a = func_00498918(1, 2);
    b = func_00498918(1, 0);
    func_005056C8(func_004A1A60(&D_00221880, 0x45), a, b, a, b);
    a = func_004A1A60(&D_00221880, 0x43);
    b = func_004A1A60(&D_00221880, 0x45);
    func_00497AE0(a, b, 0, func_00548280(*(s32 *)(obj + 0x26E4), sel), 0.004f);
    p->flags &= ~2;
}

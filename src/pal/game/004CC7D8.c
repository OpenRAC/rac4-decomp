#include "common.h"

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[0x14];
    s32 unk1C;
    u8 pad20[0x44];
} Unk004CC7D8Record;

extern Unk004CC7D8Record D_0030EAA0[];
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 D_00221A20;
extern u8 D_001CE3E0[];
extern s32 D_003D27A8[];

extern s32 func_00506BB8(void);
extern s32 func_004A2798(s32 *, s32);
extern void func_00506590(s32, s32);
extern s32 func_0049A9D8(void *, s32);
extern void func_005071B8(s32, s32);
extern s32 func_00506000(s32, s32);
extern s32 func_004CD640(s32);
extern void func_005063C0(s32, u32);
extern s32 func_004CD748(s32);
extern void func_004CCA38(s32);

void func_004CC7D8(void) {
    s32 index;
    Unk004CC7D8Record *rec;
    s32 i;
    s32 *table;
    s32 one;

    index = func_00506BB8();
    rec = (Unk004CC7D8Record *)((u32)D_0030EAA0 + (u32)(index * 0x64));
    if (D_0021EE54 == 0 && D_0021EE58 == 1) {
        func_00506590(func_004A2798(&D_00221A20, 0x35), 1);
        rec->unk1C = func_0049A9D8(D_001CE3E0, -1);
        func_005071B8(func_004A2798(&D_00221A20, 0x35), rec->unk1C);
        func_00506000(func_004A2798(&D_00221A20, 0x35), 1);
    } else {
        func_00506000(func_004A2798(&D_00221A20, 0x35), 0);
    }
    i = 0;
    table = D_003D27A8;
    one = 1;
    for (; i < 8; i++) {
        if (func_004CD640(i)) {
            func_00506000(func_004A2798(&D_00221A20, *table), 1);
            if (D_0021EE54 == 0 && D_0021EE58 == one && i < 4) {
                func_005063C0(func_004A2798(&D_00221A20, *table), 0x80404040u);
                func_00506590(func_004A2798(&D_00221A20, *table), 0x754B);
            } else {
                if (rec->unk4 < 0) {
                    rec->unk4 = i;
                }
                func_005063C0(func_004A2798(&D_00221A20, *table), 0x80808080u);
                func_00506590(func_004A2798(&D_00221A20, *table), func_004CD748(i));
            }
        } else {
            func_00506000(func_004A2798(&D_00221A20, *table), 0);
        }
        table++;
    }
    if (rec->unk4 < 0) {
        rec->unk4 = 8;
    }
    func_004CCA38(index);
}

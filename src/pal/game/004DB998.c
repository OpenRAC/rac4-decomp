#include "common.h"

typedef struct Item {
    s32 kind;
    s32 id;
    s32 cost;
    s32 unknownC;
    s32 unknown10;
    s32 label;
} Item;
typedef struct Shop {
    u8 pad00[4];
    u32 dirty;
    u8 pad08[0x1398];
    s32 mode;
    u8 pad13A4[0x14];
    s32 selected;
    u8 changed;
    u8 rebuild;
} Shop;
typedef struct List {
    u8 pad00[0x34];
    u32 rows;
    u8 pad38[0x18];
    s32 count;
    s32 selected;
} List;
extern List D_00322EA4;
extern Shop D_00321B98;
extern u8 D_00322F4C[];
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 func_004DB940(s32 id);
extern s32 func_004E7F28(Item *item, s32 player, s32 mode);
extern void func_004985F0(s32 sound);

void func_004DB998(s32 accepted)
{
    u32 row;
    s32 selected;
    Item *item;
    Shop *shop;
    s32 *previous;

    if (accepted == 0)
        return;
    selected = D_00322EA4.selected;
    if (selected < 0)
        row = 0;
    else
        row = D_00322EA4.rows + (u32)selected * 24u;
    item = *(Item **)(row + 8);
    if (func_004DB940(item->id) == 0) {
        D_00321B98.rebuild = 1;
        D_00321B98.changed = 1;
    }
    shop = &D_00321B98;
    func_004E7F28(item, 0, shop->mode);
    shop->dirty |= 5;
    if (D_0021EE54 != 0)
        goto alternate;
    if (D_0021EE58 != 1)
        goto alternate;
    if (shop->mode == 1) {
        previous = &shop->selected;
        goto selectedTarget;
    }
alternate:
    previous = (s32 *)D_00322F4C;
selectedTarget:
    if (item->id != *previous) {
        *previous = item->id;
        if (item->cost > 0)
            func_004985F0(0x21);
        else
            func_004985F0(0x16);
    } else {
        func_004985F0(4);
    }
}

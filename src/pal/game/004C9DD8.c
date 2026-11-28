#include "pal/resident_selection_menu.h"

extern s32 func_004E7F28(PalSelectionData *, s32, s32);
extern void func_004985F0(s32);

/* Apply the selected item and update the menu flags. */
void func_004C9DD8(s32 arg0)
{
    PalSelectionItem *item;
    PalSelectionData *data;

    if (arg0 == 0) {
        return;
    }
    item = pal_selected_item(&D_0030E494);
    data = item->data;
    func_004E7F28(data, -1, 0);
    D_0030D188.mark13A9 = 1;
    D_0030D188.mark13A8 = 1;
    D_0030D188.dirty |= 5;
    if (data->kind == 1) {
        func_004985F0(0x38);
    } else if (data->kind == 2) {
        func_004985F0(0x3A);
    } else {
        func_004985F0(0x21);
    }
    if (((u32)data->kind - 4) < 2) {
        D_0030D188.flag = 1;
    }
}

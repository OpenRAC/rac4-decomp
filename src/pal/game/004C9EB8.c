#include "pal/resident_selection_menu.h"

extern s32 func_004E7EC8(PalSelectionData *), func_00506BB8(void);
extern const char *func_0045E850(s32);
extern void func_004C9DD8(s32), func_004985F0(s32), func_0049F4C8(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);

void func_004C9EB8(void)
{
    if (D_0030E494.count) {
        PalSelectionData *d = pal_selected_item(&D_0030E494)->data;
        if (func_004E7EC8(d)) {
            if (d->count <= 0 || d->kind == 1)
                func_004C9DD8(1);
            else {
                s32 index = func_00506BB8();
                func_0049F4C8(index, func_0045E850(0x8D0), func_004C9DD8, 3, 0, 0, 0, -1.0f);
            }
        } else
            func_004985F0(4);
    }
}

#include "pal/menu_selection_0030A260.h"

typedef struct {
    u8 pad00[0x10];
    void (*action)(s32 direction);
} PalResidentOption;

extern PalResidentOption D_003D93E8[];
extern s32 func_00506BB8(void);

void func_004B9A10(s32 arg0) {
    PalResidentOptionState *state = pal_resident_option_state(func_00506BB8());
    u32 direction = 0xFFFFFFFF;

    if (arg0 == 0) {
        direction = 1;
    }
    D_003D93E8[state->selected].action((s32)direction);
}

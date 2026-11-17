#include "common.h"
#include "pal/mask_state.h"

u8 *D_0021E070 = 0;
extern s32 func_01EC94C0(s32 *, s32);

/* Selects the indexed network object's child and records the index when the global is empty. */
void func_0015F028(s32 arg0, s32 arg1) {
    s32 object = 0;

    if (func_01EC94C0(&object, arg1) == 0 && D_0021E070 == NULL) {
        D_0021E070 = *(u8 **)((u8 *)(u32)object + 0x1C);
        *(s32 *)(D_0021E070 + 0x1C0) = arg1;
    }
}

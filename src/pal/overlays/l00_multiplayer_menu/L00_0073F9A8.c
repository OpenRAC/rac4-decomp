#include "common.h"
#include "pal/request_761c88.h"

extern s32 func_L00_0070D100(s32, s32, s32);
extern void func_L00_0070D160(s32, s32);
extern s32 func_L00_00741FE0(void);
extern s32 func_L00_007420A0(s32, PalRequest761C88 *);
extern s32 D_00223500;
extern s32 D_00223504;

/* Register the two roster callbacks and run each once for both slots. */
void func_L00_0073F9A8(void) {
    s32 i;

    D_00223500 = func_L00_0070D100((s32)func_L00_00741FE0, 0, 0);
    D_00223504 = func_L00_0070D100((s32)func_L00_007420A0, 0, 0);
    for (i = 0; i < 2; i++) {
        func_L00_0070D160(D_00223500, i);
        func_L00_0070D160(D_00223504, i);
    }
}

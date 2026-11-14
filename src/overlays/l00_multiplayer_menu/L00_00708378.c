#include "common.h"

extern int func_00126A30();
extern s32 func_00126A90(void);
extern void func_00154BA8();
extern s32 func_00154D20(s32);
extern s32 D_00223238;
extern s32 D_172160[];

/* Releases the menu resource, resets its slot and re-queries the config. */
void func_L00_00708378(void) {
    func_00154D20(D_172160[10]);
    D_172160[10] = -1;
    func_00154BA8();
    func_00126A30(func_00126A90(), D_00223238);
}

/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00165D80[];
extern s32 D_00165E20[];
extern s32 D_00165F00[];
extern s32 D_00165F80[];
extern s32 D_00165F84[];
extern s32 D_00165F88[];

// Stores the three pointer arguments into D_00165F80, D_00165F84 and D_00165F88, each null one replaced by a fixed object.
void func_01E9AA78(void *arg0, void *arg1, void *arg2) {
    void **p0;
    void **p1;
    void **p2;

    p0 = (void **)&D_00165F80[0];
    if (arg0 == NULL) {
        arg0 = D_00165D80;
    }
    *p0 = arg0;
    p1 = (void **)&D_00165F84[0];
    if (arg1 == NULL) {
        arg1 = D_00165E20;
    }
    *p1 = arg1;
    p2 = (void **)&D_00165F88[0];
    if (arg2 == NULL) {
        arg2 = D_00165F00;
    }
    *p2 = arg2;
}

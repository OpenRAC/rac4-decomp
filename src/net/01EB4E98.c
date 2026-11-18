/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_00155AE0(s32 a);
extern s32 func_01E9BFE0(void *, s32, s32, s32);
extern s32 func_01E9C130(void *a,s32 *p);
extern s32 func_01E9D4F0(void *a, void *p);
extern s32 func_01EB5C40();
extern s32 func_01EB5D90(void *);
extern s32 func_01EB5E08(void *);
extern s32 D_001694FC[];
extern s32 D_00169500[];
extern s32 D_00169504[];
extern s32 D_00169508[];
extern s32 D_1B26C0[];
extern s32 D_1B2700[];

/* One-time setup: runs the init steps once and sets the done flag. */
s32 func_01EB4E98(void)
{
    s32 r;

    if (D_001694FC[0] != 0) {
        return 0xC351;
    }
    func_00155AE0(0);
    func_01E9BFE0(D_1B26C0, 0x800, 0x2000, 0x20);
    if (func_01E9C130(D_1B26C0, D_1B2700) < 0) {
        return 0xC350;
    }
    if (func_01E9D4F0(D_1B26C0, D_1B2700) != 0) {
        return 0xC350;
    }
    r = func_01EB5C40();
    if (r != 0) {
        return r;
    }
    if (D_00169508[0] < 0) {
        return 0xC350;
    }
    r = func_01EB5D90(D_00169500);
    if (r != 0) {
        return r;
    }
    r = func_01EB5E08(D_00169504);
    if (r == 0) {
        D_001694FC[0] = 1;
    }
    return r;
}

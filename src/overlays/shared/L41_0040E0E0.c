#include "common.h"

extern s32 func_00540020(s32);
extern void func_L00_0069DC48(s32);
extern s32 func_L00_0069DC90(void);
extern s32 func_L41_005C17C0(s32 key, u8 *out);
extern s32 D_00381550[];
// Switch context to arg0, query its table entry into a byte, restore context and return the byte.
u8 func_L41_0040E0E0(s32 arg0) {
    u8 out;
    s32 old;
    s32 idx;

    out = 0;
    old = func_L00_0069DC90();
    func_L00_0069DC48(arg0);
    idx = func_00540020(arg0);
    func_L41_005C17C0(D_00381550[idx], &out);
    func_L00_0069DC48(old);
    return out;
}

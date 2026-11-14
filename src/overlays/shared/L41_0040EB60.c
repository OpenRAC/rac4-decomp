#include "common.h"

extern void func_L00_0069DC48(s32);
extern s32 func_L00_0069DC90(void);
extern s32 func_L41_0040E4E8(s32, s32);

// Call func_L41_0040E4E8 for each of the four slots of arg0 between a saved and restored state.
void func_L41_0040EB60(s32 arg0) {
    s32 i;
    s32 old;
    old = func_L00_0069DC90();
    func_L00_0069DC48(arg0);
    for (i = 0; i < 4; i++) {
        func_L41_0040E4E8(arg0, i);
    }
    func_L00_0069DC48(old);
}

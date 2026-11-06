#include "common.h"

extern s32 func_00501458(s32 *, s32, s32, s32, s32, s32);
extern char D_00327900[];
extern char D_00661EC8[];
extern char D_00662158[];
extern char D_00662208[];

s32 D_00222C04 = 0;

/* Initialize the referenced object once and return it. */
void *func_L00_00661DD8(void) {
    if (D_00222C04 == 0) {
        func_00501458((s32 *)D_00327900, (s32)D_00661EC8, (s32)D_00662158, (s32)D_00662208, 0, 0);
        D_00222C04 = 1;
    }
    return D_00327900;
}

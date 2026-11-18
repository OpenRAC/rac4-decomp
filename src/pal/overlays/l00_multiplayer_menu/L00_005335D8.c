/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; } Type1;
extern s32 func_003FE928(s32, s32 *, s32, s32);
extern void func_00408528(s32, s32, s32);

/* Checks and stores a record whose size is in the input. */
void func_L00_005335D8(s32 arg0, Type1 *arg1) {
    s32 slot;
    if (func_003FE928(arg0, &slot, arg1->f0, arg1->f4) == 0) {
        func_00408528(arg0, slot, arg1->f4);
    }
}

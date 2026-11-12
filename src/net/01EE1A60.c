/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

extern s32 D_0016AC18;
extern s32 D_0016AC1C;
extern s32 D_0016AC20;
extern void func_01EE1690(s32);
extern void func_01EE1A10(s32);

void func_01EE1A60(void) {
    s32 p;

    while ((p = D_0016AC1C) != 0) {
        func_01EE1690(p);
        func_01EE1A10(p);
    }
    while ((p = D_0016AC18) != 0) {
        func_01EE1690(p);
        func_01EE1A10(p);
    }
    D_0016AC20 = 0;
}

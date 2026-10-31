#include "common.h"

extern void func_0046BDD0(s32);
extern s32 D_266A88[];

/* Free the value in slot arg0 of the table and clear the slot. */
void func_0046D7D8(s32 arg0) {
    s32 *slot = &D_266A88[arg0];
    if (*slot != 0) {
        func_0046BDD0(*slot);
        *slot = 0;
    }
}

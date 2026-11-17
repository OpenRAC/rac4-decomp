/* cflags: -mno-split-addresses */
#include "common.h"

extern void *D_00220D14[];

/* calls a virtual method on the object at +0x108 and sets a flag on result 0x1C */
void func_L00_0070D1A0(void) {
    void *obj;

    obj = *(void **)((u8 *)D_00220D14[0] + 0x108);
    if ((*(s32 (**)(void *))(*(u8 **)((u8 *)obj + 0x58) + 0x144))(obj) == 0x1C) {
        *(u8 *)((u8 *)obj + 0x260) = 1;
    }
}

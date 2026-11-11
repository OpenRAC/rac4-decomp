#include "common.h"

extern void *D_002233A4;
extern u8 D_172160[];

/* Clear flags on the object at 0x64 of a global one and on a global table. */
void func_L00_0077A2F8(void) {
    void *owner = D_002233A4;
    void *object = *(void **)((u8 *)owner + 0x64);
    u8 *table = D_172160;

    (*(u8 *)((u8 *)object + 0x175)) = 0;
    (*(u8 *)((u8 *)object + 0x11E)) = 0;
    (*(u8 *)(table + 0x2D5)) = 0;
    (*(s32 *)(table + 0xC)) = 0;
}

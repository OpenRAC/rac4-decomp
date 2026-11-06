#include "common.h"

#include "common.h"

extern void func_004946A8(void);
extern void func_00495148(void);
extern u8 D_2764C0[];

// Installs two function pointers into the level's callback slots.
void func_L00_00687A30(void) {
    u8 *base = D_2764C0;

    *(void **)(base + 0x184) = func_004946A8;
    *(void **)(base + 0x1FC) = func_00495148;
}

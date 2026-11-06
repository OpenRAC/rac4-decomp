#include "common.h"

#include "common.h"

extern void func_004946A8(void);
extern void func_00495148(void);
extern u8 D_2706C0[];

// Installs two function pointers into the two callback slots of the D_2706C0 block.
void func_L00_00687A30(void) {
    u8 *base = D_2706C0;

    *(void **)(base + 0x184) = func_004946A8;
    *(void **)(base + 0x1FC) = func_00495148;
}

#include "common.h"

#include "common.h"

extern void D_00617C30(void);
extern void D_0061BFB0(void);
extern u8 D_002764C0[];

// Installs two function pointers into the two callback slots of the D_002764C0 block.
void func_L00_00687A30(void) {
    u8 *base = D_002764C0;

    *(void **)(base + 0x184) = D_00617C30;
    *(void **)(base + 0x1FC) = D_0061BFB0;
}

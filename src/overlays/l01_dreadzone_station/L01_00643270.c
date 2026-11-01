#include "common.h"

#include "common.h"

extern void D_005CF9A0(void);
extern void D_005D40B0(void);
extern u8 D_00298700[];

// Installs two function pointers into the two callback slots of the D_00298700 block.
void func_L01_00643270(void) {
    u8 *base = D_00298700;

    *(void **)(base + 0x184) = D_005CF9A0;
    *(void **)(base + 0x1FC) = D_005D40B0;
}

/* cflags:  */
#include "common.h"

#include "common.h"

extern void func_00495228(void);
extern void func_00495D80(void);
extern u8 D_002765C0[];

// Installs two function pointers into the two callback slots of the D_002765C0 block.
void func_L00_0068B1F8(void) {
    u8 *base = D_002765C0;

    *(void **)(base + 0x184) = func_00495228;
    *(void **)(base + 0x1FC) = func_00495D80;
}

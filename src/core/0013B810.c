/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 open;
    u8 pad14[0x1C - 0x14];
} Ent;
extern s32 func_0012A718();
extern u8 D_1AEFC0[];
extern Ent D_1AF010[][4];
extern s32 D_1AF200[];

/* Sends request 0xE for a port/slot if its entry is open and returns the reply word. */
s32 func_0013B810(s32 port, s32 slot)
{
    if (D_1AF010[port][slot].open == 0)
        return 0;
    D_1AF200[0] = 14;
    D_1AF200[1] = port;
    D_1AF200[2] = slot;
    D_1AF200[4] = 1;
    if (func_0012A718(D_1AEFC0, 1, 0, D_1AF200, 128, D_1AF200, 128, 0, 0) < 0)
        return 0;
    D_1AF010[port][slot].open = 0;
    return D_1AF200[3];
}

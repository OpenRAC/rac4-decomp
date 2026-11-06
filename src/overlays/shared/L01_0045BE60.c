#include "common.h"

extern void func_005A2DC8(void *);
extern void func_L01_00459BE0(void *);
extern void func_L01_0045A2D0(void *);
extern s32 func_L01_0045B3A0(void *);
extern s32 func_L01_0056CDB0(void *);

// Sets the linked halfwords at +0x60E (60) and +0x610 (-1), clears +0x61E, calls func_005A2DC8,
// func_L01_0056CDB0 and func_L01_0045A2D0, and in state 5 (or 4 when func_L01_0045B3A0 agrees)
// calls func_L01_00459BE0.
void func_L01_0045BE60(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);
    u8 state;

    *(s16 *)(vars + 0x60E) = 0x3C;
    *(s16 *)(vars + 0x610) = -1;
    vars[0x61E] = 0;
    func_005A2DC8(arg0);
    func_L01_0056CDB0(arg0);
    func_L01_0045A2D0(arg0);
    state = arg0[0x67];
    if (state == 5 || (state == 4 && func_L01_0045B3A0(arg0) != 0)) {
        func_L01_00459BE0(arg0);
    }
}

#include "common.h"

extern s32 func_00159FF8(s32 a0);
extern s32 func_0015A010(s32 a0);
extern void func_L00_005C4AC0(s32, s32, s32);
extern s32 func_L00_00707A58(void);
extern void func_L00_00708378(void);
extern void func_L00_00718688(void);
extern s32 D_0021E6A4;
extern void *D_00220D14;

/* runs the setup calls, then either calls func_L00_00707A58 for modes 15 and 6 or clears 0x108 of D_00220D14 */
void func_L00_00707E30(void) {
    void *object;

    func_L00_00718688();
    func_L00_00708378();
    func_L00_005C4AC0(0, 0, 0);
    if (D_0021E6A4 == 0xF || D_0021E6A4 == 6) {
        func_L00_00707A58();
    } else {
        object = D_00220D14;
        if (object != 0) {
            *(s32 *)((u8 *)object + 0x108) = 0;
        }
    }
    func_00159FF8(0);
    func_0015A010(0);
}

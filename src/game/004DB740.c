#include "common.h"

/* extern declarations from the packet, then the function: mark the D_321B98 block active, run the init calls, and call func_00461E48 when the flag is set. */
extern void func_00461E08(int arg0);
extern void func_00461E48(int arg0);
extern void func_0046D668(void);
extern void func_00497980(s32 arg0);
extern void func_004E19D8(s32 arg0, s32 arg1);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern u8 D_321B98[];

void func_004DB740(void) {
    *(s32 *)D_321B98 = 1;
    func_00497980(6);
    func_004E19D8(0x1E, 0);
    func_00461E08(*(s32 *)(D_321B98 + 0x13B4));
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        func_00461E48(*(s32 *)(D_321B98 + 0x13B8));
    }
    func_0046D668();
}

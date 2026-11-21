/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_0011A518(void *, s32, s32);
extern void func_01EAD368(void *, void *, void *, void *);

/* Copies 64-byte blocks through 448-byte scratch buffers, mixes them with func_01EAD368, and writes the 64-byte result to arg3. */
void func_01EAE638(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u8 sp000[0x40];
    u8 sp040[0x1C0];
    u8 sp200[0x40];
    u8 sp240[0x1C0];
    u8 sp400[0x40];
    u8 sp440[0x1C0];
    u8 sp600[0x200];

    func_0011A370(sp000, arg1, 0x40);
    func_0011A518(sp040, 0, 0x1C0);
    func_0011A370(sp200, arg0, 0x40);
    func_0011A518(sp240, 0, 0x1C0);
    func_0011A370(sp400, arg2, 0x40);
    func_0011A518(sp440, 0, 0x1C0);
    func_01EAD368(sp600, sp400, sp000, sp200);
    func_0011A370(arg3, sp600, 0x40);
}

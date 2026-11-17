/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_0011A518(void *, s32, s32);
extern void func_01EACEA0();
extern void func_01EAD368(void *, void *, void *, void *);

/* Mixes two 64-byte blocks through scratch buffers and writes the 64-byte result to arg3. */
void func_01EAE578(u8 *arg0, s32 arg1, u8 *arg2, u8 *arg3) {
    u8 buf[0x200];
    u8 a[0x40];
    u8 b[0x1C0];
    u8 c[0x40];
    u8 d[0x1C0];
    u8 e[0x200];

    func_01EACEA0(buf);
    func_0011A370(a, arg0, 0x40);
    func_0011A518(b, 0, 0x1C0);
    func_0011A370(c, arg2, 0x40);
    func_0011A518(d, 0, 0x1C0);
    func_01EAD368(e, c, buf, a);
    func_0011A370(arg3, e, 0x40);
}

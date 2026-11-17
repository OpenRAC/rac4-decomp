/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern s32 func_0011AB04(void *);
extern void func_01EFC2F0(u8 *, u8 *, s32, s32);
void func_01EFD418(u8 *arg0, s32 arg1, s32 arg2) {
    u8 buf[0x200];
    func_0011A518(buf, 0, 0x200);
    func_0011A518(buf, 0x2A, func_0011AB04(arg0 + 0xB8));
    func_01EFC2F0(arg0, buf, arg1, arg2);
}

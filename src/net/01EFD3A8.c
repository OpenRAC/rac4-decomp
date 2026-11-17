/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

typedef struct {
    s32 f0;
    char _p4[0xB4];
    char fB8[1];
} Type1;
extern void func_01F0C090(void *, s32);
extern void func_0011A518(void *, s32, s32);
extern s32 func_0011AB04(char *);
extern void func_01EFBDCC(Type1 *, char *);
extern char D_0019D7B0[];
void func_01EFD3A8(Type1 *arg0) {
    char buf[0x200];
    if (arg0->f0 == 0) {
        func_01F0C090(D_0019D7B0, 0x2A);
    }
    func_0011A518(buf, 0, 0x200);
    func_0011A518(buf, 0x2A, func_0011AB04(arg0->fB8));
    func_01EFBDCC(arg0, buf);
}

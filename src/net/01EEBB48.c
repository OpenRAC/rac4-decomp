/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_0011AB04(u8 *);
extern s32 func_01EEA354(void *, void *, void *, s32, s32, void *);
extern s32 func_01EEBEA4(s32, s32);
extern void func_01EED528(s32);
extern void func_01F0C090(const char *, s32);
extern u8 D_0019B870[];

// Fills a 0x1C00-byte buffer from the object, checks its length, runs two virtual methods and the object's virtual method at 0x34, then calls func_01EEBEA4 with 0xB.
void func_01EEBB48(void *arg0) {
    s32 sp0[4];
    u8 buf[0x1C00];
    s32 sp1C10;
    s32 sp1C14;
    s32 temp_s2;
    void *temp_a0;

    temp_s2 = func_01EEA354(arg0, (u8 *)arg0 + 0x550, buf, *(s32 *)((u8 *)arg0 + 0x654), 0x1C00, (u8 *)arg0 + 0x86A4);
    if (func_0011AB04(buf) >= 0x1C00U) {
        func_01F0C090(D_0019B870, 0x51B);
    }
    (*(void (**)(void *))((u8 *)*(void **)arg0 + 0x44))(arg0);
    (*(void (**)(void *))((u8 *)*(void **)arg0 + 0x48))(arg0);
    (*(void (**)(void *, u8 *, s32, s32 *, s32 *))((u8 *)*(void **)arg0 + 0x34))(arg0, buf, temp_s2, &sp1C10, &sp1C14);
    temp_a0 = *(void **)((u8 *)arg0 + 0x20);
    if ((*(s32 (**)(void *, s32, s32, s32 *))((u8 *)*(void **)((u8 *)temp_a0 + 8) + 0x2C))(temp_a0, sp1C10, sp1C14, sp0) == 0) {
        func_01EED528(0xF);
    }
    func_01EEBEA4((s32)arg0, 0xB);
}

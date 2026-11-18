/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern s32 func_01EF04A4(s32, s32, s32, s32, s32);
extern void func_01F0C090(const char *, s32);
extern u8 D_0019D0F0[];

// Looks up an id with func_01EF04A4, stores it at +0x16C, runs func_0011A370, then calls the method at +0x8C of the object at arg0->unk80->unk0.
void func_01EF8A64(void *arg0, s32 arg1, s32 arg2) {
    void *temp_s0;
    s32 temp_v0;

    if (arg1 == 0) {
        func_01F0C090(D_0019D0F0, 0xEE);
    }
    temp_v0 = func_01EF04A4(*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x80) + 8), arg2, 4, 0xEF, (s32)D_0019D0F0);
    *(s32 *)((u8 *)arg0 + 0x16C) = temp_v0;
    if (temp_v0 == 0) {
        func_01F0C090(D_0019D0F0, 0xF0);
    }
    func_0011A370((u8 *)*(s32 *)((u8 *)arg0 + 0x16C), (u8 *)arg1, arg2);
    temp_s0 = *(void **)*(void **)((u8 *)arg0 + 0x80);
    if (temp_s0 == NULL) {
        func_01F0C090(D_0019D0F0, 0xF4);
    }
    (*(void (**)(void *, s32, s32, s32, f32, f32, s32, s32, s32))((u8 *)*(void **)temp_s0 + 0x8C))(
        temp_s0, *(s32 *)((u8 *)arg0 + 4), *(s32 *)((u8 *)arg0 + 0x16C), *(s32 *)((u8 *)arg0 + 0x15C),
        *(f32 *)((u8 *)arg0 + 0x168), *(f32 *)((u8 *)arg0 + 0x168),
        *(s32 *)((u8 *)arg0 + 0x160), *(s32 *)((u8 *)arg0 + 0x154), *(s32 *)((u8 *)arg0 + 0x158));
}

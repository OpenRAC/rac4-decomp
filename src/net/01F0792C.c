/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern s32 func_0011A8A0(void *, const u8 *);
extern s32 func_0011EB90(s32 a0);
extern s32 func_01EE38EC(s32 *arg0);
extern s32 func_01EE3900(s32 a0);
extern s32 func_01EE3960(void *arg0);
extern s32 func_01EE3A18(s32, void *);
extern s32 func_01EE3A98(void *arg0);
extern s32 func_01EE3AC0(void *arg0);
extern void func_01EE5FB8(s32 a0, void *a1, s32 *a2);
extern void func_01EEFA80(void *a0, s32 a1);
extern void func_01F075F4(char *arg0);
extern void func_01F0760C(void *arg0, s32 arg1);
extern s32 func_01F07648(s32 a0, s32 a1);
extern void func_01F0766C(u8 *a0, s32 a1);
extern void func_01F07680(void *arg0, s32 arg1);
extern void func_01F076B4(u8 *a0);
extern void func_01F076C8(void *arg0, s32 arg1);
extern s32 func_01F076D0(u8 *a0, s32 a1);
extern s32 func_01F076F8(u8 *a0, s32 a1);
extern void func_01F0C090(const char *, s32);
extern void func_01EE7010(void);
extern u8 D_0019E3C8[];
extern u8 D_0019E3F8[];
extern u8 D_0019E408[];
extern u8 D_0019E418[];
extern u8 D_0019E428[];
extern u8 D_0019E430[];

/* Builds a 0x268-byte table from the arg2 source, then fills the output record at arg4 with 3 and the count. */
void func_01F0792C(void *a0, s32 arg1, void *arg2, s32 arg3, void *arg4) {
    u8 buf[0x268];
    s32 sp270;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    func_01F075F4(buf);
    func_0011A518(buf, 0, 0x268);
    func_01F07648((s32)buf, arg3);
    func_01F07680(buf, 1);
    func_01F076B4(buf);
    func_01F0766C(buf, (s32)func_01EE7010);
    temp_v0 = func_01EE3A18(arg1, D_0019E3F8);
    if (temp_v0 != 0) {
        func_01EEFA80(D_0019E3F8, temp_v0);
    } else {
        func_01F0C090(D_0019E3C8, 0x77);
    }
    if (func_01EE3AC0(arg1) != 0) {
        arg1 = func_01EE38EC((s32 *)(s32)func_01EE3960(arg1));
    }
    while (func_01EE3A98(arg1) != 0) {
        if (func_0011A8A0(D_0019E408, (const u8 *)func_01EE3A98(arg1)) == 0) {
            temp_v0_2 = func_01EE3A18(arg1, D_0019E418);
            if (temp_v0_2 == 0) {
                func_01F0C090(D_0019E3C8, 0x87);
            }
            func_01F076C8(buf, func_0011EB90(temp_v0_2));
            temp_v0_3 = func_01EE3A18(arg1, D_0019E428);
            if (temp_v0_3 == 0) {
                func_01F0C090(D_0019E3C8, 0x8A);
            }
            func_01F076D0(buf, temp_v0_3);
        } else if (func_0011A8A0(D_0019E430, (const u8 *)func_01EE3A98(arg1)) == 0) {
            func_01F076F8(buf, func_01EE3A18(arg1, D_0019E428));
        }
        arg1 = func_01EE3900(arg1);
    }
    func_01EE5FB8(*(s32 *)((u8 *)arg2 + 0x14), buf, &sp270);
    *(s32 *)arg4 = 3;
    *(s32 *)((u8 *)arg4 + 0x8) = 1;
    *(s32 *)((u8 *)arg4 + 0xC) = sp270;
    func_01F0760C(buf, 2);
}

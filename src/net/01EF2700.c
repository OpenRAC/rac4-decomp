/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern s32 func_01EE3960(void *arg0);
extern s32 func_01EE3A18(s32, void *);
extern s32 func_01EE3AAC(void *arg0);
extern s32 func_01EE3AC0(void *arg0);
extern void *func_01EEDCD0(void *, const void *, s32);
extern void func_01EF262C(u8 *p);
extern s32 func_01EF308C(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_01EF3164(s32 arg0, void *arg1, void *arg2);
extern s32 func_01EF31D0(s32 arg0, void *arg1, void *arg2);
extern s32 func_01EF328C(s32 arg0, void *arg1, void *arg2);
extern s32 func_01EF3318(s32 arg0, void *arg1, void *arg2);
extern s32 func_01EF339C(s32 a, void *b, void *out);
extern void func_01EF382C(void *);
extern void func_01F06988(void *);
extern void func_01F0C090(const char *, s32);
extern u8 D_0016FE98[];
extern u8 D_0019C5F8[];
extern u8 D_0019C608[];
extern u8 D_0019C618[];
extern u8 D_0019C620[];
extern u8 D_0019C630[];
extern u8 D_0019C640[];
extern u8 D_0019C650[];
extern u8 D_0019C658[];
extern u8 D_0019C668[];
extern u8 D_0019C670[];

/* Initializes a record: its tables, its buffer and the first queued entry. */
void func_01EF2700(u8 *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    u8 *temp_s1;
    s32 sp0;

    temp_s1 = arg0 + 0xBC;
    func_01EF382C(arg0);
    *(u32 *)(arg0 + 0xB0) = (u32)D_0016FE98;
    func_01EF262C(arg0);
    func_01EF308C(*(s32 *)arg0, (s32)D_0019C5F8, (s32 *)(arg0 + 0xB4));
    func_01EF3164(*(s32 *)arg0, D_0019C608, arg0 + 0xC0);
    func_01EF31D0(*(s32 *)arg0, D_0019C618, arg0 + 0xB8);
    *(s32 *)(arg0 + 0x30) = -0x100;
    *(s32 *)(arg0 + 0x2C) = -1;
    func_01EF328C(*(s32 *)arg0, D_0019C620, arg0 + 0x30);
    func_01EF328C(*(s32 *)arg0, D_0019C630, temp_s1);
    if (func_01EF328C(*(s32 *)arg0, D_0019C640, &sp0) != 0) {
        *(s32 *)temp_s1 = sp0;
    }
    temp_v0 = func_01EE3A18(*(s32 *)arg0, D_0019C650);
    *(s32 *)(arg0 + 0x144) = temp_v0;
    if (temp_v0 != 0) {
        func_01F06988((void *)temp_v0);
    }
    *(s32 *)(arg0 + 0x148) = 0;
    func_01EF3318(*(s32 *)arg0, D_0019C658, arg0 + 0x148);
    temp_v0 = *(s32 *)(arg0 + 0x144);
    if (temp_v0 != 0) {
        *(s32 *)(arg0 + 0x10) = 1;
    } else {
        *(s32 *)(arg0 + 0x10) = 0;
    }
    temp_s1 = arg0 + 0xC4;
    func_01EF339C(*(s32 *)arg0, D_0019C668, arg0 + 0xA0);
    func_0011A518(temp_s1, 0, 0x80);
    if (func_01EE3AC0((void *)*(s32 *)arg0) != 0) {
        temp_v0_2 = func_01EE3AAC((void *)func_01EE3960((void *)*(s32 *)arg0));
        if (temp_v0_2 == 0) {
            func_01F0C090((const char *)D_0019C670, 0x61);
        }
        func_01EEDCD0(temp_s1, (const void *)temp_v0_2, 0x80);
    }
    func_01F06988(temp_s1);
}

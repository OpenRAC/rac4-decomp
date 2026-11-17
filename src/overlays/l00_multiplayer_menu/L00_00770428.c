#include "common.h"

typedef struct {
    u8 pad[0x2C4];
    s32 f2C4;
} Type1;

extern u16 D_00221828[];
extern s32 D_002233A4;
extern Type1 D_172160;
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED7758(u8 *obj, s32 arg1, s32 arg2);
extern s32 func_L00_00774650(u8 *obj, s32 arg1);
extern void func_0015D1A0();

/* Starts a setup request, waits until the slot is free, and writes the result through arg5 when it succeeds. */
s32 func_L00_00770428(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    u8 obj[0x28];
    u8 *s0;
    s32 s1;
    s32 v;

    *(s32 *)(obj + 0x18) = arg1;
    *(s32 *)(obj + 0x20) = arg2;
    *(u16 *)obj = D_00221828[0];
    *(s32 *)(obj + 0x24) = arg3;
    *(s32 *)(obj + 0x1C) = arg4;
    s0 = (u8 *)D_002233A4;
    arg0[0] = 1;
    s0[0] = 1;
    v = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    *(s32 *)(s0 + 8) = v;
    func_0015B548(func_01ED7758(obj, (s32)func_0015D1A0, 0));
    s1 = 1;
    while (arg0[0] != 0) {
        if (func_0015B558() != 0 || D_172160.f2C4 != 0) {
            *(s32 *)(s0 + 0x10) = 0x40;
            if (*(s32 *)(s0 + 0x14) == 0) {
                *(s32 *)(s0 + 0x14) = 0x40;
            }
            s1 = 0;
            break;
        }
        s0[0x1C] = 1;
        func_0015A050();
        s0[0x1C] = 0;
        if (func_L00_00774650(s0, 1) == 0) {
            s1 = 0;
            break;
        }
    }
    s0[0] = 0;
    arg0[0] = 0;
    if (s1 != 0) {
        if (*(s32 *)(arg0 + 4) != 0) {
            *(s32 *)(s0 + 0x10) = 0x50;
            if (*(s32 *)(s0 + 0x14) == 0) {
                *(s32 *)(s0 + 0x14) = 0x50;
            }
            s1 = 0;
        }
    }
    if (s1 != 0) {
        *arg5 = *(s32 *)(arg0 + 8);
    }
    return s1;
}

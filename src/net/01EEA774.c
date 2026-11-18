/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_0011A5D0(u8 *, u8 *);
extern s32 func_0011AB04(u8 *);
extern s8 *func_00122090(s8 *arg0);
extern void func_01EF0D44(void *arg0);
extern void func_01EF1E4C(void *, s32, u64);
extern void func_01EF1F70(void *, void *);
extern void func_01EF2190(void *, s32);
extern void func_01F0C090(const char *, s32);
extern u8 D_0019B870[];
extern u8 D_0019BA00;

typedef struct {
    u8 rec[0x70];
    u8 s70[0x10];
    u8 a80;
    u8 b81[0x100];
    u8 pad181[0xF];
    u8 c190;
    u8 d191[0x100];
} Type1;

/* Builds two packed name buffers from arg1 and arg2, hashes them with arg3, then queues the result. */
void func_01EEA774(s32 unused, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    Type1 L;
    s32 temp_s0_2;
    s32 temp_s1;
    u8 temp_s0;

    func_01EF0D44(L.rec);
    temp_s0 = D_0019BA00;
    L.a80 = temp_s0;
    func_0011A518(L.b81, 0, 0x100);
    L.c190 = temp_s0;
    func_0011A518(L.d191, 0, 0x100);
    if (func_0011AB04((u8 *)arg1) >= 0x101U) {
        func_01F0C090((const char *)D_0019B870, 0x1D6);
    }
    func_0011A5D0(&L.a80, (u8 *)arg1);
    if (func_0011AB04((u8 *)arg2) >= 0x101U) {
        func_01F0C090((const char *)D_0019B870, 0x1D8);
    }
    func_0011A5D0(&L.c190, (u8 *)arg2);
    temp_s0_2 = (s32)func_00122090((s8 *)&L.a80);
    temp_s1 = (s32)func_00122090((s8 *)&L.c190);
    func_01EF1E4C(L.rec, temp_s0_2, (u64)(u32)func_0011AB04((u8 *)temp_s0_2));
    func_01EF1E4C(L.rec, temp_s1, (u64)(u32)func_0011AB04((u8 *)temp_s1));
    func_01EF1E4C(L.rec, arg3, (u64)(u32)func_0011AB04((u8 *)arg3));
    func_01EF1F70(L.rec, L.s70);
    func_01EF2190(L.s70, arg4);
}

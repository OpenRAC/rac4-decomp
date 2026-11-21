#include "common.h"

extern s32 func_L00_00765BF0(void *, s32, s32);
extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_1ED6A28(void *, void *, s32);
extern void func_L00_005C1758(s32 a0, s32 a1, s32 a2);
extern s32 func_L00_00765DA8(void *, s32);
extern s32 func_L00_00774650(void *, s32);
extern void func_0015CBB0(void);
extern u16 D_002217B8[];
extern u8 D_172160[];
void *D_002233A4 = 0;

/* Sets up a record from the global block, polls until its flags clear, then finishes the state and returns whether it completed. */
s32 func_L00_00765498(void *arg0, s32 arg1, s32 arg2) {
    u8 loc[0x50];
    void *temp_s0;
    u8 *temp_s3;
    s32 var_s2;

    temp_s0 = D_002233A4;
    var_s2 = 1;
    if (func_L00_00765BF0(arg0, arg1, arg2) == 0) {
        return 0;
    }
    *(u16 *)loc = D_002217B8[0];
    func_0011A9EC(&loc[0x15], *(void **)((u8 *)temp_s0 + 0x64));
    func_L00_005C1758((s32)&loc[0x26], arg2, 0x20);
    *((u8 *)arg0 + 0x2A) = 1;
    *(u8 *)temp_s0 = 1;
    *(s32 *)((u8 *)temp_s0 + 0x8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_1ED6A28(loc, (void *)func_0015CBB0, 0));
    temp_s3 = D_172160;
    while (*((u8 *)arg0 + 0x2A) != 0) {
        if ((func_0015B558() != 0) || (*(s32 *)(temp_s3 + 0x2C4) != 0)) {
            *(s32 *)((u8 *)temp_s0 + 0x10) = 0xD;
            if (*(s32 *)((u8 *)temp_s0 + 0x14) == 0) {
                *(s32 *)((u8 *)temp_s0 + 0x14) = 0xD;
            }
            var_s2 = 0;
            break;
        }
        *((u8 *)temp_s0 + 0x1C) = 1;
        func_0015A050();
        *((u8 *)temp_s0 + 0x1C) = 0;
        if (func_L00_00774650(temp_s0, 1) == 0) {
            var_s2 = 0;
            break;
        }
    }
    *(u8 *)temp_s0 = 0;
    *((u8 *)arg0 + 0x2A) = 0;
    if (var_s2 != 0 && *(s32 *)((u8 *)arg0 + 0x12C) != 0) {
        *(s32 *)((u8 *)temp_s0 + 0x10) = 0xD;
        if (*(s32 *)((u8 *)temp_s0 + 0x14) == 0) {
            *(s32 *)((u8 *)temp_s0 + 0x14) = 0xD;
        }
        var_s2 = 0;
    }
    if (func_L00_00765DA8(arg0, 1) == 0) {
        return 0;
    }
    if (var_s2 != 0) {
        *(s32 *)((u8 *)temp_s0 + 0x10) = 0;
        *(s32 *)((u8 *)temp_s0 + 0x14) = 0;
    }
    return var_s2;
}

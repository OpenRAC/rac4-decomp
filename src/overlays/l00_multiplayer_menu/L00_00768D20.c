#include "common.h"

extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED5098(u8 *obj, s32 arg1, s32 arg2);
extern s32 func_L00_0076B4E8(void *, u8, s32);
extern s32 func_L00_00774650(void *, s32);
extern void func_0015D038(void);
extern void *D_002233A4;
extern u16 D_002217E0[];
extern u8 D_172160[];

// Arms a request on the menu slot, polls until it answers, then reports the outcome.
s32 func_L00_00768D20(u8 *arg0, s32 arg1) {
    u8 sp[0x30];
    void *temp_s1;
    void *temp_a1;
    u16 temp_u16;
    u8 *temp_s0;
    s32 var_s3;
    s32 temp_v1;
    s32 var_v1;

    temp_s1 = D_002233A4;
    temp_u16 = D_002217E0[0];
    temp_a1 = *(void **)((u8 *)temp_s1 + 0x64);
    *(u16 *)sp = temp_u16;
    func_0011A9EC(sp + 0x15, temp_a1);
    *(s32 *)(sp + 0x28) = arg1;
    arg0[0xA0] = 1;
    *(u8 *)temp_s1 = 1;
    *(s32 *)((u8 *)temp_s1 + 0x8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED5098(sp, (s32)&func_0015D038, 0));
    var_s3 = 1;
    temp_s0 = D_172160;
    while (arg0[0xA0] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(temp_s0 + 0x2C4) != 0) {
            *(s32 *)((u8 *)temp_s1 + 0x10) = 0x22;
            if (*(s32 *)((u8 *)temp_s1 + 0x14) == 0) {
                *(s32 *)((u8 *)temp_s1 + 0x14) = 0x22;
            }
            var_s3 = 0;
            break;
        }
        *(u8 *)((u8 *)temp_s1 + 0x1C) = 1;
        func_0015A050();
        *(u8 *)((u8 *)temp_s1 + 0x1C) = 0;
        if (func_L00_00774650(temp_s1, 1) == 0) {
            var_s3 = 0;
            break;
        }
    }
    *(u8 *)temp_s1 = 0;
    arg0[0xA0] = 0;
    if (var_s3 != 0) {
        temp_v1 = *(s32 *)(arg0 + 0xA4);
        if (temp_v1 == -0x3DE) {
            var_v1 = 0x23;
        } else {
            if (temp_v1 == 0) {
                goto block_64;
            }
            var_v1 = 0x22;
        }
        *(s32 *)((u8 *)temp_s1 + 0x10) = var_v1;
        if (*(s32 *)((u8 *)temp_s1 + 0x14) == 0) {
            *(s32 *)((u8 *)temp_s1 + 0x14) = var_v1;
        }
        var_s3 = 0;
    }
block_64:
    if (var_s3 != 0 && arg0[0x4F8] != 0 && arg0[0x500] == 0) {
        var_s3 = func_L00_0076B4E8(arg0, arg0[0x4F0], *(s32 *)(arg0 + 0x4F4));
    }
    return var_s3;
}

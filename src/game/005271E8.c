#include "common.h"

extern void func_004A7C50(int arg0);
extern void func_00522868(void *arg0, s32 arg1);
extern void func_00547C90(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0054A580(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_00171B40[];
extern s32 D_00220D70;

/* For each of four table slots at D_00171B40+0x27, resets matching tags in arg0's fields and calls the slot helpers when the tag is set. */
void func_005271E8(void *arg0) {
    u8 *base = D_00171B40;
    u8 *var_s1;
    s32 *var_s2;
    s32 var_s3;
    s32 two = 2;
    u8 btwo = 2;

    var_s3 = 0;
    var_s1 = base + 0x27;
    var_s2 = &D_00220D70;
    do {
        if (var_s1[2] != 0) {
            if (*var_s2 == var_s1[2]) {
                *var_s2 = two;
            }
            if (*(s32 *)((u8 *)arg0 + 0x24B0) == var_s1[2]) {
                *(s32 *)((u8 *)arg0 + 0x24B0) = two;
            }
            if (var_s1[0] == var_s1[2]) {
                var_s1[0] = btwo;
            }
            if (*(s32 *)((u8 *)arg0 + 0x2318) == var_s1[2]) {
                func_00522868(arg0, 2);
                *(s32 *)((u8 *)arg0 + 0x268C) = 0;
            }
            func_004A7C50(var_s3);
            if (*(s32 *)((u8 *)arg0 + 0x268C) == var_s1[2]) {
                *(s32 *)((u8 *)arg0 + 0x268C) = 0;
            }
            if (*(s32 *)((u8 *)arg0 + 0x2674) == var_s1[2]) {
                *(s32 *)((u8 *)arg0 + 0x2674) = two;
                *(s32 *)((u8 *)arg0 + 0x268C) = 0;
            }
            func_0054A580(*(s32 *)((u8 *)arg0 + 0x26E4), var_s1[2], 1);
            func_00547C90(*(s32 *)((u8 *)arg0 + 0x26E4), var_s1[2], -1);
        }
        var_s3 += 1;
        var_s1 += 1;
        var_s2 += 1;
    } while (var_s3 < 4);
}

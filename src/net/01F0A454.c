/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 func_0011A8A0(void *, const u8 *);
extern s32 func_0011EB90(s32 a0);
extern s32 func_01EE3960(void *arg0);
extern s32 func_01EE3A98(void *arg0);
extern s32 func_01EE3AAC(void *arg0);
extern s32 func_01EF3470(s32 arg0, s32 arg1);
extern s32 func_01F0A710(void *, s32);
extern s32 func_01F0A870(void *, s32);
extern void func_01F0C090(const char *, s32);
extern s32 D_0019E5D8[];
extern s32 D_0019E5F0[];
extern s32 D_0019E600[];
extern s32 D_0019E610[];
extern s32 D_0019E618[];
extern s32 D_0019E620[];

/* Looks arg1 up in two tables and calls back through arg3 with the result. */
void func_01F0A454(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s0;
    void *temp_a0;
    void *temp_a0_2;
    void *obj;

    if (func_0011A8A0((void *)func_01EE3A98((void *)arg1), (const u8 *)D_0019E5F0) == 0) {
        temp_v0 = func_01EF3470(arg1, (s32)D_0019E610);
        if (temp_v0 != 0) {
            temp_s2 = func_01F0A710(arg0, temp_v0);
            temp_v0_2 = func_01EF3470(arg1, (s32)D_0019E618);
            if (temp_v0_2 != 0) {
                *(s32 *)((u8 *)arg0 + 0x210) = func_0011EB90(func_01EE3AAC((void *)func_01EE3960((void *)temp_v0_2)));
            }
            temp_a0 = *(void **)((u8 *)arg3 + 0x10);
            obj = *(void **)((u8 *)temp_a0 + 0x10);
            ((void (*)(void *, s32))((s32 *)obj)[4])(temp_a0, temp_s2);
        } else {
            if (func_01F0A870(arg0, arg1) == 0) {
                func_01F0C090((const char *)D_0019E5D8, 0x7B);
            }
        }
    } else {
        if (func_0011A8A0((void *)func_01EE3A98((void *)arg1), (const u8 *)D_0019E600) == 0) {
            var_s0 = 1;
            temp_v0_3 = func_01EF3470(arg1, (s32)D_0019E610);
            if (temp_v0_3 != 0) {
                temp_v0_4 = func_01EF3470(temp_v0_3, (s32)D_0019E620);
                if (temp_v0_4 != 0) {
                    var_s0 = func_0011EB90(func_01EE3AAC((void *)func_01EE3960((void *)temp_v0_4))) != 0x4FC6;
                }
            }
            temp_a0_2 = *(void **)((u8 *)arg3 + 0x10);
            obj = *(void **)((u8 *)temp_a0_2 + 0x10);
            ((void (*)(void *, s32))((s32 *)obj)[9])(temp_a0_2, var_s0);
            return;
        }
        func_01F0C090((const char *)D_0019E5D8, 0xA1);
    }
}

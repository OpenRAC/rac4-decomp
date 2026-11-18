/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_0011A8A0(void *, const u8 *);
extern s32 func_0011AB04(u8 *);
extern void func_01F0C090(const char *, s32);
extern u8 D_0019E158[];
extern u8 D_0019E160[];

// Walks the record blocks of the table at arg0; each record func_0011AB04 accepts is looked up, then dispatched through its owner's vtable.
void func_01F04CEC(void **arg0, void *arg1, s32 arg2) {
    s32 fp = 0;
    s32 sp0 = arg2;
    s32 var_s5;
    s32 var_s6;
    void **var_s1;
    char *temp_v0;
    u8 *temp_s3;
    s32 temp_s7;
    u8 *var_s0;
    void *temp_a0;
    void *fn;

    if (*(s32 *)((char *)arg0 + 0x28) > 0) {
        var_s1 = arg0;
        do {
            var_s6 = 0;
            var_s5 = 0;
loop_3:
            temp_v0 = (char *)*var_s1 + var_s5;
            var_s5 += 0x24;
            temp_s3 = (u8 *)(temp_v0 + 4);
            temp_s7 = *(s32 *)temp_v0;
            if (func_0011AB04(temp_s3) != 0) {
                var_s0 = D_0019E158;
                if (arg1 != NULL) {
                    fn = ((void **)((void **)arg1)[0x2C])[0xF];
                    var_s0 = ((u8 *(*)(void *))fn)(arg1);
                }
                if (var_s0 == NULL) {
                    func_01F0C090((const char *)D_0019E160, 0x45);
                }
                if (func_0011A8A0(temp_s3, var_s0) == 0 && temp_s7 == sp0) {
                    temp_a0 = *var_s1;
                    fn = ((void **)((void **)temp_a0)[0x18D])[4];
                    ((void (*)(void *, void *, s32))fn)(temp_a0, arg1, sp0);
                }
                var_s6 += 1;
                if (var_s6 < 0x20) {
                    goto loop_3;
                }
            }
            fp += 1;
            var_s1 += 1;
        } while (fp < *(s32 *)((char *)arg0 + 0x28));
    }
}

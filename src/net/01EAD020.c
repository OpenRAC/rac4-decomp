/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_01EACEA0(s32 *p, s32 x);
extern void func_01EACF38(s32 arg0, u32 arg1);
extern u32 func_01EAD5D8(void *);
extern s32 func_01EAD6AC(void *, void *);
extern void func_01EAD714(void *, s32);
extern void func_01EAD840(void *, s32);
extern void func_01EADA00(void *, void *);

// Copies two 0x200-byte blocks, then runs a length-merge loop over the buffers.
void func_01EAD020(u8 *arg0, u8 *arg1, s32 *arg2, u8 *arg3) {
    u8 buf[0x200];
    u32 var_s0;
    u32 var_s1;
    u32 temp_s2;
    s32 var_s4;
    u32 temp;

    func_0011A370(buf, arg1, 0x200);
    func_0011A370(arg3, arg0, 0x200);
    var_s1 = func_01EAD5D8(arg3);
    var_s0 = func_01EAD5D8(buf);
    func_01EACEA0(arg2, 0);
    temp_s2 = var_s0;
    if (var_s0 < var_s1) {
        temp = var_s1 - var_s0;
        var_s0 = var_s1;
        func_01EAD840(buf, temp);
    }
    var_s4 = var_s1 < temp_s2;
    while (1) {
        if (var_s4 != 0) {
            return;
        }
        if (var_s1 < var_s0) {
            temp = var_s0 - var_s1;
            var_s0 = var_s1;
            func_01EAD714(buf, temp);
        }
        if (func_01EAD6AC(arg3, buf) != 0) {
            func_01EADA00(arg3, buf);
            var_s1 = func_01EAD5D8(arg3);
            func_01EACF38(arg2, var_s0 - temp_s2);
            var_s4 = var_s1 < temp_s2;
            continue;
        }
        if (temp_s2 >= var_s0) {
            return;
        }
        var_s0 -= 1;
        func_01EAD714(buf, 1);
    }
}

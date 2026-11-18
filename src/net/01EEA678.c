/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_01EF0D44(void *arg0);
extern s32 func_0011AB04(u8 *arg0);
extern void func_01EF1E4C(void *arg0, void *arg1, u64 arg2);
extern void func_01EF1F70(void *arg0, void *arg1);
extern void func_01EF2190(void *arg0, void *arg1);
extern u8 D_0019B9F8[];

/* Feeds arg1, arg2 + 8, arg3 and D_0019B9F8 through func_01EF1E4C on a local buffer, then runs the final pair of calls. */
void func_01EEA678(s32 arg0, u8 *arg1, s8 *arg2, u8 *arg3, void *arg4) {
    u8 buf[0x80];
    u8 *temp_s0;
    s32 flag;

    func_01EF0D44(buf);
    func_01EF1E4C(buf, arg1, (u32)func_0011AB04(arg1));
    flag = *arg2;
    arg2 = (s8 *)((u8 *)arg2 + 8);
    if (flag != 0) {
        func_01EF1E4C(buf, arg2, (u32)(func_0011AB04((u8 *)arg2) - 2));
    }
    if (arg3 != NULL) {
        func_01EF1E4C(buf, arg3, (u32)func_0011AB04(arg3));
    }
    temp_s0 = D_0019B9F8;
    func_01EF1E4C(buf, temp_s0, (u32)func_0011AB04(temp_s0));
    func_01EF1F70(buf, buf + 0x70);
    func_01EF2190(buf + 0x70, arg4);
}

/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_004FAD28(s32);
extern void *func_L00_004FACD8();
extern void func_L00_00538098(void *, s32);
extern s32 func_L00_0053B9C0(void *arg0, void *arg1, s32 arg2);
extern s32 func_L00_00547998(void *a0, u8 **out, s32 a2, void *a3);

// Runs one of two checks on the object at arg0 for request arg2 (1 or 3); returns 1 on failure, 0 on success.
s32 func_L00_0053B2B0(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *buf;
    u8 *obj;
    s32 temp_s0;
    s32 temp_s3;
    s32 temp_a0;
    u8 *s1;

    if (arg2 == 1) {
        s1 = *(u8 **)((u8 *)arg0 + 0x10);
        temp_s3 = func_L00_0053B9C0(s1, arg1, arg4);
        temp_s0 = *(s32 *)*(u8 **)arg0;
        if (*(s32 *)((u8 *)arg1 + 4) < temp_s0) {
            func_L00_00538098(s1 + 0xC, temp_s0);
            func_L00_00538098(s1 + 0x20, temp_s0);
        }
        return temp_s3 == 0;
    }
    if (arg2 == 3) {
        temp_s0 = func_L00_00547998(arg1, &buf, arg3, (void *)arg4);
        if (temp_s0 >= 2) {
            temp_a0 = *(s32 *)((u8 *)arg0 + 0x14);
            if (temp_a0 != 0) {
                func_004FAD28(temp_a0);
            }
            obj = func_L00_004FACD8(temp_s0);
            *(u8 **)((u8 *)arg0 + 0x14) = obj;
            if (obj != 0) {
                func_0011A370(obj, buf, temp_s0);
                return 0;
            }
            return 1;
        }
    }
    return 1;
}

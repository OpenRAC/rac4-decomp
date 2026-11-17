/* cflags: @ee29 -O2 -G0 -msingle-float */
#include "common.h"

extern void func_0011A5D0(u8 *, u8 *);
extern s32 func_0011AB04(u8 *);
extern void *func_004FAD00(void *, s32, s32);
extern void func_004FAD28(void *);
extern void *func_L00_004FACD8(s32);
extern void func_L00_005407E8(s32 a0, s32 a1);

/* Adds each non-null variadic argument to a growing buffer, then closes it with code 3. */
void func_L00_0051A148(s32 arg0, ...) {
    u8 *arg;
    u8 *buf;
    s32 total;
    s32 i;
    u8 *ap;
    s32 cap;
    void *temp_v0;
    s32 temp_a2;

    cap = 0x40;
    buf = func_L00_004FACD8(0x41);
    if (buf != NULL) {
        *buf = 0;
        ap = (u8 *)__builtin_next_arg(arg0) - 0x38;
        total = 0;
        for (i = 0; i < arg0; i++) {
            ap += 8;
            arg = *(u8 **)(ap - 8);
            if (arg != NULL) {
                total += func_0011AB04(arg);
                temp_a2 = cap + 1;
                if (cap < total) {
                    cap = total + 0x14;
                    temp_v0 = func_004FAD00(buf, total + 0x15, temp_a2);
                    if (temp_v0 == NULL) {
                        func_004FAD28(buf);
                        return;
                    }
                    buf = temp_v0;
                }
                func_0011A5D0(buf, arg);
            }
        }
        func_L00_005407E8(buf, 3);
    }
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_00517808(void);
extern void *func_L00_004FACD8(s32);
extern void func_L00_0051AD48(void *arg0, s32 arg1, s32 *arg2);

// Initializes object arg0 from arg1, allocates its buffer, then asks arg1's hook whether to keep it.
s32 func_L00_005167E8(void *arg0, void *arg1) {
    s32 temp_s2;
    void *temp_v0;
    s32 temp_v1;
    s32 (*temp_a1)(void *);

    temp_s2 = *(s32 *)func_00517808();
    *(void **)((u8 *)arg0 + 0x0) = arg1;
    *(s32 *)((u8 *)arg0 + 0x4) = 0;
    *(s32 *)((u8 *)arg0 + 0x8) = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
    *(s32 *)((u8 *)arg0 + 0x1C) = 0;
    *(s32 *)((u8 *)arg0 + 0x20) = 0;
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    *(s32 *)((u8 *)arg0 + 0x24) = 0;
    *(s64 *)((u8 *)arg0 + 0x30) = 0;
    *(s64 *)((u8 *)arg0 + 0x38) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 1;
    *(s32 *)((u8 *)arg0 + 0x2C) = 1;
    temp_v0 = func_L00_004FACD8(8);
    *(void **)((u8 *)arg0 + 0x40) = temp_v0;
    if (temp_v0 == 0) {
        return 0;
    }
    func_L00_0051AD48((void *)temp_s2, (s32)arg0, temp_v0);
    temp_a1 = *(s32 (**)(void *))((u8 *)arg1 + 0x1C);
    if (temp_a1 != 0) {
        temp_v1 = temp_a1(arg0);
        if (temp_v1 == 0) {
            return 0;
        }
    }
    return 1;
}

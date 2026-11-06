#include "common.h"

extern s32 func_001639D0(void);
extern void func_00163550(s32);
extern void func_001638E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_0046A500(s32, s32);

s32 func_004A3988(s32 arg0, s32 arg1)
{
    s32 result;
    s32 value;
    s32 flags = *(s32 *)arg0;

    if ((flags ^ 0x10) == 0) {
        result = func_001639D0();
        if (result != 0) {
            goto end;
        }
        func_00163550(1);
        value = *(s32 *)(arg0 + 0x1C);
        value = (value << 3) + *(s32 *)(arg0 + 0x14);
        func_001638E8(0, *(s32 *)(arg0 + 0xC),
                      *(s32 *)value + *(s32 *)(arg0 + 0x18),
                      *(s32 *)(value + 4), 0, 0, 0);
        flags = 4;
        *(s32 *)arg0 = flags;
        goto done;
    }
    if ((flags ^ 8) == 0) {
        result = func_001639D0();
        if (result != 0) {
            goto end;
        }
        value = 1;
        goto store;
    }
    if ((flags ^ 4) != 0) {
        goto end;
    }
    result = func_001639D0();
    if (result != 0) {
        goto end;
    }
    arg1 = *(s32 *)(arg0 + 0x10);
    if (arg1 == 0) {
        value = 2;
        goto store;
    }
    func_0046A500(*(s32 *)(arg0 + 0xC), arg1);
    value = 2;
store:
    *(s32 *)arg0 = value;
done:
end:
    return 1;
}

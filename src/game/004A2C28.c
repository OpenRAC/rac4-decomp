#include "common.h"

extern s32 func_00163928(void);
extern void func_001634A8(s32);
extern void func_00163840(s32, s32, s32, s32, s32, s32, s32);
extern void func_00469C40(s32, s32);

s32 func_004A2C28(s32 arg0, s32 arg1)
{
    s32 result;
    s32 value;
    s32 flags = *(s32 *)arg0;

    if ((flags ^ 0x10) == 0) {
        result = func_00163928();
        if (result != 0) {
            goto end;
        }
        func_001634A8(1);
        value = *(s32 *)(arg0 + 0x1C);
        value = (value << 3) + *(s32 *)(arg0 + 0x14);
        func_00163840(0, *(s32 *)(arg0 + 0xC),
                      *(s32 *)value + *(s32 *)(arg0 + 0x18),
                      *(s32 *)(value + 4), 0, 0, 0);
        flags = 4;
        *(s32 *)arg0 = flags;
        goto done;
    }
    if ((flags ^ 8) == 0) {
        result = func_00163928();
        if (result != 0) {
            goto end;
        }
        value = 1;
        goto store;
    }
    if ((flags ^ 4) != 0) {
        goto end;
    }
    result = func_00163928();
    if (result != 0) {
        goto end;
    }
    arg1 = *(s32 *)(arg0 + 0x10);
    if (arg1 == 0) {
        value = 2;
        goto store;
    }
    func_00469C40(*(s32 *)(arg0 + 0xC), arg1);
    value = 2;
store:
    *(s32 *)arg0 = value;
done:
end:
    return 1;
}

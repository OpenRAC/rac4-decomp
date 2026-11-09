/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s32 func_0053BEE0(void);
void func_L00_004F84C8(s32, s32, s32, s32, s32);
s32 func_L00_00516768(s32);
void func_L00_005168B0(s32);
s32 func_L00_00516C48(s32, s32, s32, s32);
void func_L00_00519EC8(void);
s64 func_L00_00519F20(void);
s32 func_L00_0051D3D8(s32, s32, s32);
s32 func_L00_0052DF18(s32, s32);
void func_L00_00530618(s32);
s32 func_L00_00541DD8(s32, s32);

s32 func_L00_0053D010(u8 *arg0, s32 arg1, s32 arg2) {
    s32 result = 0;
    s32 item = 0;
    s32 count = 0;
    s32 list;

    if (arg1 == 0) {
        return 1;
    }
    list = func_L00_00516768(func_0053BEE0());
    if (list == 0 || func_L00_00516C48(list, 0x6C, 3, arg1) <= 0) {
        func_L00_004F84C8(0xB, 0xE0, 0x802, 0, 0);
    } else if (arg2 == 1) {
        for (;;) {
            item = func_L00_0051D3D8(list, 0, 0);
            if (item == 0) {
                if ((s32)(func_L00_00519F20() & 0xFFF) == 0x6C && count > 0) {
                    break;
                }
                func_L00_004F84C8(0xB, 0xE0, 0x809, 0, 0);
                goto done;
            }
            if (func_L00_00541DD8(*(s32 *)(arg0 + 0x10), item) == 0) {
                goto done;
            }
            count++;
            func_L00_00530618(item);
        }
        result = count;
        func_L00_00519EC8();
    } else if (arg2 == 2) {
        item = func_L00_0052DF18(list, 0);
        if (item == 0) {
            func_L00_004F84C8(0xB, 0xE0, 0x80D, 0, 0);
        } else {
            result = func_L00_00541DD8(*(s32 *)(arg0 + 0x10), item);
        }
    } else {
        func_L00_004F84C8(0xB, 0xE0, 0x9A, 0, 0);
    }
done:
    if (item != 0) {
        func_L00_00530618(item);
    }
    if (list != 0) {
        func_L00_005168B0(list);
    }
    return result;
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 b0;
    u8 pad1[3];
    u32 len;
    u8 pad8[8];
    void *data;
} Type1;

void *func_0051AF50(void *arg0);
s32 func_0051A6E0(void *arg0);
s32 func_L00_0051B060(void *arg0, u8 *arg1, s32 arg2, s32 arg3);
void func_L00_0051B208(void *arg0, void *arg1, u32 arg2);
s32 func_L00_0051B210(void *arg0, s32 arg1, s32 *arg2);

s32 func_L00_0052BC90(u8 *arg0, s32 arg1, s32 arg2) {
    u8 buf[5];
    s32 result;
    void *obj;
    Type1 *info;
    u8 *name;
    u8 *counter;
    s32 i;
    u8 *p;

    if (arg2 != 0) {
        u8 *base = *(u8 **)(arg0 + 0x54);
        obj = *(void **)(arg0 + 0x78);
        info = (Type1 *)(base + 0xCC);
        name = base + 0x30;
        counter = base + 0x28;
    } else {
        u8 *base = *(u8 **)(arg0 + 0x54);
        obj = *(void **)(arg0 + 0x6C);
        info = (Type1 *)(base + 0xB4);
        name = base + 0x14;
        counter = base + 0xC;
    }
    result = func_0051A6E0(func_0051AF50(obj));
    buf[0] = info->b0;
    buf[1] = 3;
    buf[2] = 1;
    buf[3] = info->len >> 8;
    buf[4] = info->len;
    if (func_L00_0051B060(obj, name, result, 0) == 0) {
        return 0;
    }
    func_L00_0051B208(obj, counter, 8);
    func_L00_0051B208(obj, buf, 5);
    func_L00_0051B208(obj, info->data, info->len);
    if (func_L00_0051B210(obj, arg1, &result) == 0) {
        return 0;
    }
    for (i = 7; i >= 0; i--) {
        if (++counter[i] != 0) {
            break;
        }
    }
    return result;
}

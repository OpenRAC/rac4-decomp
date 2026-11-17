/* cflags: -fno-opt-stack */
#include "common.h"

extern s32 func_0011D5D8(const char *fmt, ...);
extern s32 func_001480B0(s32 arg0);
extern s32 func_0014E1E8(void *arg0, s32 arg1);
extern s32 func_0014EDE0(u8 **arg0);
extern s32 *(*D_0016F740[])(s32, s32);
extern u16 D_0016F748[];
extern s32 D_0016F750[];
extern char D_001A2350[];
extern char D_001A2380[];

/* Creates a 0x38-byte object into *arg0 and links it; returns an error code otherwise. */
s32 func_0014ECA8(u8 **arg0) {
    s32 temp;
    s32 t;
    s32 a1;
    u8 *obj;

    if (arg0 == 0) {
        return 0x181A;
    }
    *arg0 = 0;
    temp = func_001480B0(0);
    if (temp == 1) {
        func_0011D5D8(D_001A2350);
        return 0x1965;
    }
    if (temp == -1) {
        func_0011D5D8(D_001A2380);
        return 0x1965;
    }
    obj = (u8 *)D_0016F740[0](1, 0x38);
    if (obj == 0) {
        goto block_14;
    }
    *arg0 = obj;
    obj[0x18] = 0xA;
    *(s64 *)obj = 0xFACE;
    *(s64 *)(obj + 0x8) = 0x64;
    *(s64 *)(obj + 0x10) = 0xBB8;
    if (D_0016F750[0] != 3) {
        a1 = *(s32 *)(obj + 0x24);
    } else {
        t = (s32)D_0016F740[0](0x1000, 1);
        *(s32 *)(obj + 0x30) = t;
        if (t == 0) {
            goto block_14;
        }
        t = (s32)D_0016F740[0](0x1000, 1);
        *(s32 *)(obj + 0x34) = t;
        if (t == 0) {
            goto block_14;
        }
        a1 = *(s32 *)(obj + 0x24);
    }
    if (func_0014E1E8(obj + 0x1C, a1) == 0) {
        D_0016F748[0] += 1;
        return 0;
    }
    func_0014EDE0(arg0);
block_14:
    return 0x1770;
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad[0x1C];
    void *f1C;
} T517B20;

extern s32 func_0051ED70(void *arg0, u8 *arg1, u32 *arg2, u32 arg3, s32 arg4, u32 arg5, s32 arg6);
extern s32 func_L00_0051EE28(void *arg0, s32 arg1, s32 arg2, u32 *arg3);

s32 func_L00_00517B20(T517B20 *arg0, s32 arg1, u32 want, u8 *buf, u32 *len) {
    u32 size;
    u32 have;
    s32 diff;
    s32 i;
    s32 j;
    s32 result;

    if (arg0->f1C == 0) {
        result = 0x2722;
    } else if ((result = func_L00_0051EE28(arg0->f1C, 0x103, 0, &size)) == 0) {
        result = 0x2711;
        if (size == want) {
            if ((result = func_0051ED70(arg0->f1C, buf, len, want, arg1, want, 0)) != 0) {
                result = 0x2711;
            } else {
                have = *len;
                if (have < size) {
                    diff = want - have;
                    i = want - 1;
                    j = have - 1;
                    for (; i >= diff; i--, j--) {
                        buf[i] = buf[j];
                    }
                    for (; i >= 0; i--) {
                        buf[i] = 0;
                    }
                    *len = want;
                } else {
                    result = (size < have) ? 0x2711 : 0;
                }
            }
        }
    }
    return result;
}

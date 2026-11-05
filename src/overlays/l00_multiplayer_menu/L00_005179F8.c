/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad[0x1C];
    void *f1C;
} T5179F8;

extern s32 func_L00_0051ED40(void *arg0, s32 arg1);
extern s32 func_L00_0051EDC0(void *arg0, u8 *arg1, u32 *arg2, u32 arg3, s32 arg4);
extern s32 func_L00_0051EE28(void *arg0, s32 arg1, s32 arg2, u32 *arg3);

/* reads data into buf, right-aligning it to the full size and zero-padding the front */
s32 func_L00_005179F8(T5179F8 *arg0, u8 *buf, u32 *len) {
    u32 size;
    u32 have;
    s32 diff;
    s32 i;
    s32 j;
    s32 result;

    if (arg0->f1C == 0) {
        result = 0x2722;
    } else if ((result = func_L00_0051ED40(arg0->f1C, 0)) == 0
            && (result = func_L00_0051EE28(arg0->f1C, 0x103, 0, &size)) == 0
            && (result = func_L00_0051EDC0(arg0->f1C, buf, len, size, 0)) == 0) {
        have = *len;
        if (have < size) {
            diff = size - have;
            i = size - 1;
            j = have - 1;
            for (; i >= diff; i--, j--) {
                buf[i] = buf[j];
            }
            for (; i >= 0; i--) {
                buf[i] = 0;
            }
            *len = size;
        } else {
            result = (size < have) ? 0x2711 : 0;
        }
    }
    return result;
}

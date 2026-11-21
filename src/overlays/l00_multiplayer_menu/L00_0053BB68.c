/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_004FAD28(void *);
extern s32 func_00520DC8(s32, void *, s32);
extern void *func_L00_004FACD8();
extern void *func_L00_00538590(unsigned char *s, int len, void *ret);

/* Builds a bit-pattern buffer from a source, sets marker bits, runs a check, and frees it. */
s32 func_L00_0053BB68(s32 a0, s32 a1, s32 n, s32 a3, s32 t0) {
    s32 last = (n + 7) / 8;
    s32 bit = (n - 1) % 8;
    s32 len = last + 1;
    s32 mask = 0xFF << bit;
    s32 ret = 0;
    u8 *buf = func_L00_004FACD8(len);

    if (buf != 0) {
        func_00520DC8(a1, buf, len);
        if (a3 != 0) {
            if (bit == 0) {
                buf[0] = 1;
                if (last >= 2) {
                    buf[1] |= 0x80;
                }
            } else {
                buf[0] = (buf[0] | (3 << (bit - 1))) & ~(mask << 1);
            }
        } else {
            buf[0] = (buf[0] | (1 << bit)) & ~(mask << 1);
        }
        if (t0 != 0) {
            buf[last - 1] |= 1;
        }
        ret = func_L00_00538590(buf, last, (void *)a0) != 0;
        func_0011A518(buf, 0, last);
        func_004FAD28(buf);
    }
    return ret;
}

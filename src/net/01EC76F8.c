/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

extern s32 func_01EA9850(u8 *arg0, u16 *arg1);

u32 func_01EC76F8(u8 *arg0, u32 arg1, u32 arg2) {
    u8 buf[4];
    u8 *end;
    u8 *p;
    u32 acc;
    u32 next;
    u32 t;
    u16 v;

    p = arg0;
    acc = 0;
    if (arg2 >= arg1) {
        acc = arg1;
    } else {
        end = arg0 + arg1;
        while (p < end) {
            buf[0] = *p;
            func_01EA9850(p + 1, (u16 *)&buf[2]);
            v = *(u16 *)&buf[2];
            t = v + 3;
            if (v != 0 && (buf[0] & ~0x7F)) {
                t = v + 7;
            }
            next = acc + t;
            if (arg2 < next) {
                break;
            }
            p += t;
            acc = next;
        }
    }
    return acc;
}

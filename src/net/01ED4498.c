/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern char *func_0011AFC8(char *, char *, s32);
extern s32 func_01ED5528(void);
extern s32 func_01ED5538(void);
extern s32 func_01ED5DD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_01ED46A8();
extern s32 D_00169BC0[];
extern s8 D_00169BC8[];
extern s32 D_00169BDC[];
extern s32 D_00169C90[];
extern s32 D_00169CC0[];
extern s32 D_1B7648[];

typedef struct {
    s32 w[0x19];
} Blk;

/* Stores a request block from arg0 and sends it with func_01ED5DD0. */
s32 func_01ED4498(s8 *arg0, s32 arg1, s32 arg2) {
    s8 buf[0x1B4];
    s32 st;
    s8 *s3;
    s32 ret;

    if ((D_1B7648[0] == 0) || ((st = func_01ED5538()) != 1)) {
        return -5;
    }
    if (func_01ED5528() == 0) {
        return -6;
    }
    s3 = arg0 + 0x8;
    D_00169BDC[0] = *(s32 *)arg0;
    func_0011AFC8(D_00169BC8, s3, 0x14);
    D_00169C90[0] = arg1;
    D_00169CC0[0] = (s32) func_01ED46A8;
    D_00169BC8[0x13] = 0;
    if (D_00169BC0[0] < 5) {
        if (D_00169BC0[0] > 0) {
            buf[4] = st;
            buf[5] = st;
            *(s32 *)(buf + 0x8) = *(s32 *)arg0;
            *(s32 *)(buf + 0xC) = *(s32 *)(arg0 + 0x4);
            *(s32 *)buf = arg2;
            func_0011AFC8(buf + 0x10, s3, 0x100);
            buf[0x10F] = 0;
            func_0011AFC8(buf + 0x110, arg0 + 0x108, 0x40);
            buf[0x14F] = 0;
            *(Blk *)(buf + 0x150) = *(Blk *)(arg0 + 0x148);
            ret = -7;
            if (func_01ED5DD0(1, 0xDE, 0x1B4, (s32) buf) == 0) {
                ret = 0;
            }
            return ret;
        }
    }
    return 0;
}

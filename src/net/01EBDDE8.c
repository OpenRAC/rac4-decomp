/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char _p4[0x10]; s32 f14[4]; s32 f24[4]; } Ctx;
s32 func_01EB6748(s32 *arg0, u32 arg1);
s32 func_01EBDDE8(s32 o, Ctx *c, s32 which, u32 a3) {
    if (o == 0) {
        return 0xD2F2;
    }
    if (c == 0) {
        return 0xD2F3;
    }
    if (c->f0 == 0) {
        return 0xD2F3;
    }
    if (a3 == 0) {
        return 2;
    }
    if (which == 0) {
        return func_01EB6748(c->f14, a3);
    }
    if (which == 1) {
        return func_01EB6748(c->f24, a3);
    }
    return 2;
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct { u8 pad[0x14]; s32 x14; u8 pad18[4]; s32 x1C; s32 x20; } R_12A468;
typedef struct { u8 pad[0x14]; s32 x14; u8 pad18[4]; s32 x1C; s32 x20; s32 x24; s32 x28; } K_12A468;
typedef struct U_12A468 { s32 x0; s32 x4; s32 x8; u8 pad[0x2C]; struct U_12A468 *x38; } U_12A468;
extern K_12A468 *func_0012A020(void *);
extern U_12A468 *func_0012A3D8(s32, void *);
extern s32 func_00129B58(s32, void *, s32, s32, s32, s32);
extern s32 func_0012A428(s32, s32, s32, void *);
extern s32 func_0012EAA8(s32, s32 (*)(s32, s32, s32, void *), void *);

/* from rac3-decomp's func_00122560 */
void func_0012A468(R_12A468 *req, void *data) {
    K_12A468 *k;
    U_12A468 *srv;
    k = func_0012A020(data);
    {
        s32 b = req->x14;
        s32 a = req->x1C;
        k->x1C = a;
        k->x14 = b;
    }
    k->x20 = 0x80000009;
    srv = func_0012A3D8(req->x20, data);
    if (srv == 0) {
        k->x24 = 0;
        k->x28 = 0;
    } else {
        k->x24 = (s32)srv;
        k->x28 = srv->x8;
    }
    if (func_00129B58(0x80000008, k, 0x40, 0, 0, 0) == 0) {
        func_0012EAA8(0x800, func_0012A428, k);
    }
}

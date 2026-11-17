/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x100]; u32 f100; } Ctx;
typedef struct { char _p0[0x138]; s32 f138; } Tab;
typedef struct { s32 f0; u8 f4; s32 f8; s32 fC; char _p10[0x24]; s32 f34; s32 f38; u16 *f3C; } Req;
typedef struct { s32 w[12]; } Out;
extern Ctx *D_00167F38;
extern Tab D_001B7258;
extern void func_01EC9CB0(u32);
extern void *func_0011A518(void *, s32, u32);
extern void func_01EA1270(Req *, Out *, s32);
s32 func_01EC9DD0(u32 id) {
    Req req;
    Out out;
    u16 h[1];
    if (id >= D_00167F38->f100) {
        return 0x17;
    }
    if (D_001B7258.f138 == 0) {
        return 8;
    }
    func_01EC9CB0(id);
    h[0] = id;
    func_0011A518(&req, 0, sizeof(req));
    req.f0 = D_001B7258.f138;
    req.f4 = 0x50;
    req.fC = -1;
    req.f34 = 0x100;
    req.f8 = 10;
    req.f38 = 2;
    req.f3C = h;
    func_01EA1270(&req, &out, 0);
    return 0;
}

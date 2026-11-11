/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_0012E168 (src/boot_elf/core/12E050.c, GPL-3.0), the same code in both games. */

extern s32 func_00126BF0(s32);
extern s32 func_00126BC0(s32);
extern s32 func_0012A718();
extern int func_00126BC0();
extern int func_00126BF0();
extern s32 func_0012A718(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern int D_00167BFC;
extern u8 D_001AEE40[];
extern s32 D_00167BFC;
extern s32 D_00167BF8[];
extern void func_0013A148();
extern s32 D_00167BF8[];
extern s32 D_00167BFC;
extern u8 D_001AEE40[];
extern void func_0013A148(void);
extern u8 D_001AEE40[];
extern s32 D_00167BFC;
typedef struct {
    u8 pad0[0x24];
    s32 server;
} Cd_12E168;
typedef struct {
    s32 fd;
    u8 pad4[0xC - 4];
    s32 rest;
    u8 pad10[0x14 - 0x10];
    u32 head;
    u8 *tail;
    u8 pad1C[0x20 - 0x1C];
    u8 data[16];
} Rpc_12E168;
extern Cd_12E168 D_001AD880;
extern Rpc_12E168 D_001AD900;
extern u8 D_001AEE40[];
extern s32 D_00167BFC;
extern s32 D_00167BF8[];
extern void func_00126E20(s32);
s32 func_0013A628(s32 fd, u8 *buf, s32 size)
{
    u32 i;
    s32 n;
    if (D_001AD880.server == 0) {
        return -100;
    }
    if (func_00126BF0(D_00167BFC) < 0) {
        return -200;
    }
    D_001AD900.fd = fd;
    if (size < 0x11) {
        D_001AD900.head = size;
        D_001AD900.rest = 0;
        D_001AD900.tail = 0;
    } else {
        {
            u8 *p = buf - 0x10;
            n = (u8 *)((u32)(buf - 1) & ~0xF) - p;
        }
        D_001AD900.head = n;
        D_001AD900.rest = size - n;
        D_001AD900.tail = buf + n;
    }
    for (i = 0; i < D_001AD900.head; i++) {
        D_001AD900.data[i] = buf[i];
    }
    func_00126E20(0);
    if (func_0012A718(&D_001AD880, 6, 1, &D_001AD900, 0x30, D_001AEE40, 4, func_0013A148, 0) != 0) {
        func_00126BC0(D_00167BFC);
        return -91;
    }
    D_00167BF8[0] = 6;
    return 0;
}

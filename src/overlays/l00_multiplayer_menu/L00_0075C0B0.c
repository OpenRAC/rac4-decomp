#include "common.h"

typedef struct { s32 f0; u8 f4; u8 f5; u8 f6; u8 pad[25]; } Args;
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x248]; s32 f254; s32 f258; u8 pad2[0x59C]; u8 f7F8; } G;
extern G D_00172160[];
extern s32 D_0021DBD8;
extern void func_01E9E270(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, void *t1);

/* Store a value in the object and, if idle, send a request. */
void func_L00_0075C0B0(u8 *obj, s32 a1, s32 a2) {
    Args buf;
    *(s32 *)(obj + 0x26C) = a1;
    buf.f6 = 1;
    buf.f0 = a2;
    buf.f5 = 0;
    buf.f4 = 0;
    if (D_00172160->f258 == 0) {
        func_01E9E270(D_00172160->f7F8 | 0x50, D_00172160->f8, D_00172160->f254, D_0021DBD8, 0x20, &buf);
    }
}

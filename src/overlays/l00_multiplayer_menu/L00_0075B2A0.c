#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 f8;
    u8 padC[0x258 - 0xC];
    s32 f258;
    u8 pad25C[0x644 - 0x25C];
    s32 f644[10];
    s32 f66C[10];
    u8 pad694[0x7F8 - 0x694];
    u8 f7F8;
} Type1;

typedef struct {
    u8 pad0[0x104];
    u8 f104[10];
    u8 f10E[10];
    u8 pad118[0x1A6 - 0x118];
    u8 f1A6;
} Type2;

extern void func_01E9E270(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, void *t1);
extern Type1 D_172160[];
extern s32 D_0021DBD8;
extern Type2 *D_0021DFE8;

/* Clears the pending entries of a ten-entry table, then flags arg0 when the count of players in state 6 equals a total. */
void func_L00_0075B2A0(u8 *arg0) {
    u8 buf[0x18];
    s32 i;
    s32 count;

    count = 1;
    for (i = 1; i < 10; i++) {
        if (D_172160[0].f644[i] != -1) {
            *(s32 *)buf = i;
            buf[5] = 0;
            buf[4] = 0;
            buf[6] = D_172160[0].f66C[i];
            if (D_172160[0].f258 == 0) {
                func_01E9E270(D_172160[0].f7F8 | 0x50, D_172160[0].f8, D_172160[0].f644[i], D_0021DBD8, 0x20, buf);
            }
            D_172160[0].f644[i] = -1;
        }
        if (D_0021DFE8->f104[i] != 0xFF && D_0021DFE8->f10E[i] == 6) {
            count++;
        }
    }
    arg0[0x260] = count == D_0021DFE8->f1A6;
}

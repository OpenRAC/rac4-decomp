/* Not matching yet: BYTES 112/192 (tools/try_func.py func_004EA6D0 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    u8 pad[0x20];
    u8 f20;
    u8 pad2[0x13];
    u16 f34;
} Obj;

typedef struct {
    Obj *f0;
    s32 f4;
} Entry;

extern u8 D_328548[];
extern s32 func_004534D0(s32 *);

void func_004EA6D0(s32 arg0) {
    Entry *e = (Entry *)D_328548;
    s32 i;
    for (i = 0; i < 0x20; i++, e++) {
        if (e->f4 != arg0) continue;
        if ((e->f0->f34 & 0x1000) == 0) {
            e->f4 = 0;
        } else if (e->f0 == 0 || e->f0->f20 == 0xFE || e->f0->f20 == 0xFD) {
            e->f4 = 0;
        } else if (func_004534D0((s32 *)((u8 *)e + 8)) != 0) {
            e->f4 = 0;
        }
    }
}

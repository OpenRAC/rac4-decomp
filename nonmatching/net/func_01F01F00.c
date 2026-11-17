/* Not matching yet: SIZE ours 200 / retail 196   (standalone) (tools/try_func.py func_01F01F00 --diff). Not part of the build. */
/* cflags: @ee32-040921 -O2 -G0 -fno-strength-reduce */
#include "common.h"

typedef struct Elem Elem;
typedef struct Elem2 Elem2;

struct Elem {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
};

struct Elem2 {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x20 - 8];
};

typedef struct {
    u8 pad00[0x10];
    s32 f10;
    u8 pad14[0xB4 - 0x14];
    s32 fB4;
    u8 padB8[0xBC - 0xB8];
    s32 fBC;
    u8 padC0[0xCC - 0xC0];
    Elem **fCC;
    Elem2 *fD0;
    u8 padD4[0xE4 - 0xD4];
    s32 fE4;
    s32 fE8;
} Big;

s32 func_01F01F00(Big *a) {
    s32 i;
    s32 j;
    s32 off;
    Elem *e;

    if (a->fBC > 0) {
        i = 0;
        do {
            if (a->fB4 > 0) {
                j = 0;
                off = 0;
                do {
                    e = (Elem *)((char *)a->fCC[i] + off);
                    if (e->f4 != 0) {
                        a->fE4 = i;
                        a->fE8 = j;
                        return (a->f10 = 1);
                    }
                    j++;
                    off += 0x18;
                } while (j < a->fB4);
            }
            i++;
        } while (i < a->fBC);
    }
    for (j = 0; j < a->fB4; j++) {
        if (a->fD0[j].f4 != 0) {
            a->f10 = 1;
            a->fE4 = -1;
            a->fE8 = j;
            return 1;
        }
    }
    a->f10 = 0;
    return 0;
}

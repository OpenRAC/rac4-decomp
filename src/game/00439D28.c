#include "common.h"

typedef struct {
    u32 flags;
    s16 h[2];
    u8 pad[0x14 - 8 ];
} Hdr;

typedef struct {
    s32 a;
    s32 b;
    s32 id;
} E1;

typedef struct {
    s32 w;
    u8 pad[0xC];
} E2;

extern Hdr D_0020B9C0;
extern E2 D_0020B9D4[];
extern E1 D_0020BA10[];

s32 func_00439D28(s32 arg) {
    s32 i;
    s32 j;

    if (!(D_0020B9C0.flags & 1)) {
        return 1;
    }
    for (i = 0; i < 0x30; i++) {
        if (arg == D_0020BA10[i].id) {
            break;
        }
    }
    if (i == 0x30) {
        return 1;
    }
    for (j = 0; j < 3; j++) {
        if (arg == ((D_0020B9D4[j].w << 4) >> 16)) {
            s8 st = (s8)D_0020B9D4[j].w;
            if (st != 3 && st != 1 && st != 0) {
                return 1;
            }
        }
    }
    return 0;
}

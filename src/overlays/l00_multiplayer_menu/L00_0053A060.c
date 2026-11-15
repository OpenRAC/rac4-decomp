/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct { s32 a; s32 b; s32 c; s32 d; } Entry;
typedef struct { u8 b[16]; } Raw;

extern Entry D_00476F88[];
extern s32 D_004A3054[];

/* Inserts a 16-byte entry (four words) at position arg4 of a 32-entry table, shifting the entries above it up. */
s32 func_L00_0053A060(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;

    if (D_004A3054[0] >= 0x20) {
        return 1;
    }
    for (i = D_004A3054[0]; arg4 < i; i--) {
        *(Raw *)&D_00476F88[i] = *(Raw *)&D_00476F88[i - 1];
    }
    D_00476F88[i].a = arg0;
    D_00476F88[i].b = arg1;
    D_00476F88[i].c = arg2;
    D_00476F88[i].d = arg3;
    D_004A3054[0] += 1;
    return 0;
}

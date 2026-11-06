#include "common.h"

typedef struct { u8 data[0x18]; } Entry;
extern void func_005433E0(Entry *);
extern Entry D_00354EA0[];
s32 D_00220E4C = 0;

/* Calls func_005433E0 on each of the first D_00220E4C 0x18-byte entries of D_00354EA0, then sets the count to 0. */
void func_00543338(void) {
    s32 i;
    for (i = 0; i < D_00220E4C; i++) {
        func_005433E0(&D_00354EA0[i]);
    }
    D_00220E4C = 0;
}

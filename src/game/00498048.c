#include "common.h"

typedef struct { char _p0[0x28]; s32 n; s32 f2C[10]; } E;
extern E D_002F32B8[];
void func_00497EB8(s32, s32);
void func_00498048(s32 i) {
    if (D_002F32B8[i].n > 0) {
        D_002F32B8[i].n--;
        func_00497EB8(i, D_002F32B8[i].f2C[D_002F32B8[i].n]);
    }
}

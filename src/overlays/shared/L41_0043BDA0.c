#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; } Type1;
extern Type1 D_00385DC8[];
extern Type1 D_00385DCC[];

// Find the 12-byte entry whose key matches, return its payload (entry 0 if none).
Type1 *func_L41_0043BDA0(s32 key) {
    s32 found = 0;
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_00385DC8[i].f0 == key) {
            found = i;
            break;
        }
    }
    return &D_00385DCC[found];
}

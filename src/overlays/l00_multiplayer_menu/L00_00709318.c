#include "common.h"

typedef struct { char pad[4]; s8 bytes[2]; char pad2[2]; s32 a; s32 b; } Entry;
s32 D_00220A04 = 0;
extern Entry D_003E4F00[];

/* Append an entry and return its index. */
s32 func_L00_00709318(s32 arg0, s32 arg1, s32 arg2) {
    s32 index = D_00220A04++;
    s32 i;
    for (i = 1; i >= 0; i--) D_003E4F00[index].bytes[i] = arg2;
    D_003E4F00[index].a = arg0;
    D_003E4F00[index].b = arg1;
    return index;
}

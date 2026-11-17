#include "common.h"

typedef struct { u8 a; u8 b; u8 c; } Ent;
extern Ent D_004CEFB0[];
s32 func_L00_006F5628(s32 arg0) {
    return (((D_004CEFB0[arg0].c << 16) | 0x80000000) | (D_004CEFB0[arg0].b << 8)) | D_004CEFB0[arg0].a;
}

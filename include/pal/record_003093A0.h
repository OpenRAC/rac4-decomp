#ifndef PAL_RECORD_003093A0_H
#define PAL_RECORD_003093A0_H
#include "common.h"
/* The existing word grid and the independently observed word at +0x58. */
typedef struct {
    u8 bytes_00[0x18];
    s32 value[4][4];
    s32 word_58;
    u8 bytes_5c[8];
} PalRecord003093A0;
typedef char PalRecord003093A0SizeCheck[(sizeof(PalRecord003093A0) == 0x64) ? 1 : -1];
typedef char PalRecord003093A0AlignmentCheck[(__alignof__(PalRecord003093A0) == 4) ? 1 : -1];
extern PalRecord003093A0 D_003093A0[];
#endif

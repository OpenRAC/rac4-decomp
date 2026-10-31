#ifndef PAL_RECORD_003099F0_H
#define PAL_RECORD_003099F0_H
#include "common.h"
/* PAL resident table: only the accessed word fields and 0x1F8 stride are known. */
typedef struct {
    u8 unk00[0x0C];
    s32 unk0C;
    s32 unk10;
    u8 unk14[0x1E4];
} PalRecord003099F0;
extern PalRecord003099F0 D_003099F0[];
#endif

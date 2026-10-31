#ifndef PAL_DECOMP_H
#define PAL_DECOMP_H
/* Spellings shared by PAL reconstructions drafted with m2c. */
#include "common.h"

typedef s32 M2C_UNK;
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

#endif
